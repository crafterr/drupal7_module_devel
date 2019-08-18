<?php

/**
 * @file
 * Provide the administrative related function for the Article block module
 */
function article_block_posts() {

}

function article_block_settings_form() {
  $form = [];
  $form['article_block_maxposts'] = [
    '#type' => 'textfield',
    '#title' => t('Number of items to show'),
    '#description' => t('The maximum number of item nodes to show'),
    '#default_value' => variable_get('article_block_maxposts',3),
    '#size' => 2,
    '#maxlength' => 2,
    '#required' => TRUE
  ];

  $form['article_block_types'] = [
    '#type' => 'checkboxes',
    '#title' => t('The content type to enable Block for'),
    '#description' => t('On the specific content type block option will be enabled'),
    '#default_value' => variable_get('article_block_types',[]),
    '#options' => node_type_get_names(),
    '#required' => TRUE
  ];

  return system_settings_form($form);

}

/**
 * Implements hook_validate().
 */
function article_block_settings_form_validate($form, &$form_state) {
  $maxpost = $form_state['values']['article_block_maxposts'];

  if(!filter_var($maxpost, FILTER_VALIDATE_INT) !== false){
    form_set_error('article_block_maxposts',t('Value must be integer'));
  }

  if (($maxpost <= 0)) {
    form_set_error('article_block_maxposts',t('Value can not be less that 0 or 0'));
  }
}