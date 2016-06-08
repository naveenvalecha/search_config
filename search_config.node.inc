<?php

/**
 * Does the string overrides unconditional on what other changes are pending for
 * the form.
 */
function _search_config_set_string_overrides(&$form, $form_state) {
  $labels = search_config_string_overrides('labels');

  // The two submit buttons.
  if (isset($form['basic']['submit']) && !empty($labels['basic_submit'])) {
    $form['basic']['submit']['#value'] = t('!search_config:basic_submit', array('!search_config:basic_submit' => $labels['basic_submit']));
  }
  if (isset($form['advanced']['submit']) && !empty($labels['advanced_submit'])) {
    $form['advanced']['submit']['#value'] = t('!search_config:advanced_submit', array('!search_config:advanced_submit' => $labels['advanced_submit']));
  }

  // Other form elements. Map into an array to iterate over each element.
  $title_display = search_config_string_overrides('title_display');
  $label_elements = array();
  if (isset($form['basic'])) {
    $label_elements['basic'] = &$form['basic']['keys'];
  }
  if (isset($form['advanced'])) {
    $label_elements['advanced_fieldset'] = &$form['advanced'];
    $label_elements['advanced_type'] = &$form['advanced']['type'];

    $fkeywords = &$form['advanced']['keywords'];
    $label_elements['advanced_any'] = &$fkeywords['or'];
    $label_elements['advanced_phrase'] = &$fkeywords['phrase'];
    $label_elements['advanced_none'] = &$fkeywords['negative'];

    if (isset($form['advanced']['language'])) {
      $label_elements['advanced_language'] = &$form['advanced']['language'];
    }
  }

  foreach ($label_elements as $key => $element) {
    if (empty($element)) {
      continue;
    }
    if (!empty($fkeys['#default_value']) && !empty($labels[$key . '_with_keys'])) {
      $label_elements[$key]['#title'] = t('!search_config:' . $key, array('!search_config:' . $key => $labels[$key . '_with_keys']));
    }
    elseif (!empty($labels[$key])) {
      $label_elements[$key]['#title'] = t('!search_config:' . $key, array('!search_config:' . $key => $labels[$key]));
    }
    if (!empty($title_display[$key])) {
      switch ($title_display[$key]) {
        case 'description':
          $label_elements[$key]['#description'] = $label_elements[$key]['#title'];
          $label_elements[$key]['#title_display'] = 'invisible';
          break;

        case 'invisible':
          $label_elements[$key]['#title_display'] = 'invisible';
          break;

        case 'default':
        default:

      }
    }
  }
}
