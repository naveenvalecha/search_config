<?php

/*
 * @file
 *
 * contains \Drupal\search_config\searchConfigPermissions
 */

namespace  Drupal\search_config;
class searchConfigPermissions {
    public function permissions() {
        $permissions = [];
        foreach (search_config_content_types() as $type => $label) {
            $permissions["search $type content"] = array(
                'title' => t('%type_name: Search content of this type', array('%type_name' => $label)),
            );
        }
        return $permissions;
    }
}
