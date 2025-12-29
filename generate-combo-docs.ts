#!/usr/bin/env bun

import { readFileSync, writeFileSync } from 'fs';
import { join } from 'path';

// QWERTY layout structure (5x6 Dactyl Manuform)
const LAYOUT = {
  rows: [
    // Row 0: Number row
    ['KC_GRV', 'KC_1', 'KC_2', 'KC_3', 'KC_4', 'KC_5', 'KC_6', 'KC_7', 'KC_8', 'KC_9', 'KC_0', 'KC_BSPC'],
    // Row 1: Top letter row
    ['KC_TAB', 'KC_Q', 'KC_W', 'KC_E', 'KC_R', 'KC_T', 'KC_Y', 'KC_U', 'KC_I', 'KC_O', 'KC_P', 'KC_MINS'],
    // Row 2: Home row
    ['OSM_SFT', 'KC_A', 'KC_S', 'KC_D', 'KC_F', 'KC_G', 'KC_H', 'KC_J', 'KC_K', 'KC_L', 'KC_SCLN', 'SFT_QT'],
    // Row 3: Bottom row
    ['KC_DEL', 'KC_Z', 'KC_X', 'KC_C', 'KC_V', 'KC_B', 'KC_N', 'KC_M', 'KC_COMM', 'KC_DOT', 'KC_SLSH', 'KC_BSLS'],
  ],
  thumbs: [
    // Inner thumb keys
    ['KC_GRV', 'A_TAB', 'KC_PLUS', 'KC_EQL'],
    // Main thumb keys
    ['LT(_RAISE,KC_TAB)', 'KC_SPC', 'KC_ENT', 'LT(_LOWER,KC_CAPS)'],
    // Middle thumb keys
    ['KC_LALT', 'KC_LCTL', 'KC_RCTL', 'KC_RALT'],
    // Outer thumb keys
    ['TG(_GAME)', 'KC_LGUI', 'KC_RGUI', 'CG_TOGG'],
  ]
};

interface Combo {
  name: string;
  result: string;
  keys: string[];
  type: 'COMB' | 'SUBS';
}

function parseComboLine(line: string): Combo | null {
  // Match COMB or SUBS, then capture name, result (with or without quotes), and keys
  const combMatch = line.match(/^(COMB|SUBS)\((\w+)\s*,\s*("([^"]+)"|([^,]+?))\s*,\s*(.+)\)$/);
  if (!combMatch) return null;

  const [, type, name, , quotedResult, unquotedResult, keysStr] = combMatch;
  // Use quotedResult if present, otherwise use unquotedResult, then trim
  const result = (quotedResult || unquotedResult).trim();
  
  // Split by comma but handle LT(_LOWER, KC_CAPS) as a single key
  const keys: string[] = [];
  let currentKey = '';
  let parenDepth = 0;
  
  for (let i = 0; i < keysStr.length; i++) {
    const char = keysStr[i];
    if (char === '(') parenDepth++;
    if (char === ')') parenDepth--;
    
    if (char === ',' && parenDepth === 0) {
      const trimmed = currentKey.trim();
      if (trimmed) keys.push(trimmed);
      currentKey = '';
    } else {
      currentKey += char;
    }
  }
  
  // Don't forget the last key
  const trimmed = currentKey.trim();
  if (trimmed) keys.push(trimmed);

  return {
    name,
    result,
    keys,
    type: type as 'COMB' | 'SUBS',
  };
}

function parseCombosDef(filePath: string): Combo[] {
  const content = readFileSync(filePath, 'utf-8');
  const lines = content.split('\n');
  const combos: Combo[] = [];

  for (const line of lines) {
    const trimmed = line.trim();
    if (trimmed.startsWith('//') || !trimmed) continue;
    
    const combo = parseComboLine(trimmed);
    if (combo) combos.push(combo);
  }

  return combos;
}

function findCombo(combos: Combo[], modifierKey: string, targetKey: string): string | null {
  // Normalize the modifier key to handle variations
  const normalizedModifier = modifierKey.replace(/\s+/g, '');
  
  const combo = combos.find(c => {
    if (c.keys.length !== 2) return false;
    
    // Normalize keys for comparison
    const normalizedKeys = c.keys.map(k => k.replace(/\s+/g, ''));
    
    return normalizedKeys.includes(normalizedModifier) && normalizedKeys.includes(targetKey);
  });
  
  if (!combo) return null;
  
  // Format result nicely - keep the original result if it's already a quoted string
  return combo.result;
}

function generateLayoutForModifier(combos: Combo[], modifierKey: string, modifierLabel: string): string {
  let output = `## ${modifierLabel} Combos\n\n`;
  output += `Pressing **${modifierLabel}** + any key shows the result below:\n\n`;
  output += '```\n';

  // Generate each row
  for (let rowIdx = 0; rowIdx < LAYOUT.rows.length; rowIdx++) {
    const row = LAYOUT.rows[rowIdx];
    const leftHalf = row.slice(0, 6);
    const rightHalf = row.slice(6);

    // Left side
    let leftStr = '';
    for (const key of leftHalf) {
      const result = findCombo(combos, modifierKey, key);
      const display = result ? formatResult(result) : '_______';
      leftStr += display.padEnd(9, ' ');
    }

    // Right side
    let rightStr = '';
    for (const key of rightHalf) {
      const result = findCombo(combos, modifierKey, key);
      const display = result ? formatResult(result) : '_______';
      rightStr += display.padEnd(9, ' ');
    }

    output += leftStr + '    ' + rightStr + '\n';
  }

  // Thumb cluster (simplified - just show the modifier key position)
  output += '\n';
  output += '           _______  _______                                  _______  _______\n';
  output += '                    _______  ';
  output += modifierKey === 'KC_SPC' ? '[SPACE]' : '_______';
  output += '      ';
  output += modifierKey === 'KC_ENT' ? '[ENTER]' : '_______';
  output += '  ';
  output += modifierKey === 'LT(_LOWER,KC_CAPS)' ? '[CAPS] ' : '_______';
  output += '\n';

  output += '```\n\n';

  return output;
}

function formatResult(result: string): string {
  // Clean up the result for display
  if (result.startsWith('"') && result.endsWith('"')) {
    // Return string content without outer quotes but keep it recognizable as text
    return result; // Keep quotes to show it's a string output
  }
  
  // Remove KC_ prefix for cleaner display
  if (result.startsWith('KC_')) {
    const cleaned = result.substring(3);
    // Special handling for common symbols
    const symbolMap: Record<string, string> = {
      'EXLM': '!',
      'AT': '@',
      'HASH': '#',
      'DLR': '$',
      'PERC': '%',
      'CIRC': '^',
      'AMPR': '&',
      'ASTR': '*',
      'LPRN': '(',
      'RPRN': ')',
      'MINS': '-',
      'PLUS': '+',
      'EQL': '=',
      'LBRC': '[',
      'RBRC': ']',
      'LCBR': '{',
      'RCBR': '}',
      'PIPE': '|',
      'BSLS': '\\',
      'SCLN': ';',
      'QUOT': "'",
      'DQT': '"',
      'GRV': '`',
      'TILD': '~',
      'COMM': ',',
      'DOT': '.',
      'SLSH': '/',
      'QUES': '?',
      'LT': '<',
      'GT': '>',
      'UNDS': '_',
    };
    
    return symbolMap[cleaned] || cleaned;
  }
  
  return result;
}

function generateAdjacentCombosList(combos: Combo[]): string {
  let output = '## Adjacent Key Combos\n\n';
  output += 'Press two adjacent keys simultaneously:\n\n';

  const adjacentCombos = combos.filter(c => {
    if (c.keys.length !== 2) return false;
    const normalizedKeys = c.keys.map(k => k.replace(/\s+/g, ''));
    return !normalizedKeys.includes('KC_SPC') &&
           !normalizedKeys.includes('KC_ENT') &&
           !normalizedKeys.includes('LT(_LOWER,KC_CAPS)') &&
           !normalizedKeys.includes('KC_RCTL');
  });

  if (adjacentCombos.length === 0) {
    output += '_No adjacent key combos defined._\n\n';
    return output;
  }

  output += '| Keys | Result | Description |\n';
  output += '|------|--------|-------------|\n';

  for (const combo of adjacentCombos) {
    const keys = combo.keys.map(k => k.replace('KC_', '')).join(' + ');
    const result = formatResult(combo.result);
    output += `| ${keys} | ${result} | ${combo.name} |\n`;
  }

  output += '\n';
  return output;
}

function generateOtherCombosList(combos: Combo[]): string {
  let output = '## Other Combos\n\n';

  // RCTRL combos
  const rctrlCombos = combos.filter(c => {
    const normalizedKeys = c.keys.map(k => k.replace(/\s+/g, ''));
    return normalizedKeys.includes('KC_RCTL');
  });
  
  if (rctrlCombos.length > 0) {
    output += '### Right Control Number Combos\n\n';
    output += '| Keys | Result |\n';
    output += '|------|--------|\n';
    for (const combo of rctrlCombos) {
      const otherKey = combo.keys.find(k => k.replace(/\s+/g, '') !== 'KC_RCTL')?.replace('KC_', '') || '';
      output += `| RCTRL + ${otherKey} | ${formatResult(combo.result)} |\n`;
    }
    output += '\n';
  }

  // Multi-key combos (3+ keys)
  const multiKeyCombos = combos.filter(c => c.keys.length >= 3);
  if (multiKeyCombos.length > 0) {
    output += '### Multi-Key Combos\n\n';
    output += '| Keys | Result | Type |\n';
    output += '|------|--------|------|\n';
    for (const combo of multiKeyCombos) {
      const keys = combo.keys.map(k => k.replace('KC_', '').replace(/LT\(_LOWER,\s*/, 'CAPS+')).join(' + ');
      const result = combo.type === 'SUBS' ? `"${combo.result}"` : formatResult(combo.result);
      output += `| ${keys} | ${result} | ${combo.type === 'SUBS' ? 'Text' : 'Key'} |\n`;
    }
    output += '\n';
  }

  return output;
}

function generateCombosDocs(combosDefPath: string, outputPath: string): void {
  console.log('Parsing combos.def...');
  const combos = parseCombosDef(combosDefPath);
  console.log(`Found ${combos.length} combos`);

  let markdown = '# Keyboard Combo Reference\n\n';
  markdown += '_Auto-generated from combos.def_\n\n';
  markdown += '---\n\n';

  // Space combos
  markdown += generateLayoutForModifier(combos, 'KC_SPC', 'Space');

  // Enter combos
  markdown += generateLayoutForModifier(combos, 'KC_ENT', 'Enter');

  // CapsLock combos
  markdown += generateLayoutForModifier(combos, 'LT(_LOWER,KC_CAPS)', 'CapsLock');

  // Tab combos
  markdown += generateLayoutForModifier(combos, 'LT(_RAISE, KC_TAB)', 'Tab');

  // Adjacent key combos
  markdown += generateAdjacentCombosList(combos);

  // Other combos
  markdown += generateOtherCombosList(combos);

  // Write output
  writeFileSync(outputPath, markdown);
  console.log(`✓ Generated ${outputPath}`);
}

// Main execution
const combosDefPath = join(import.meta.dir, 'combos.def');
const outputPath = join(import.meta.dir, 'combos_doc.md');

generateCombosDocs(combosDefPath, outputPath);

