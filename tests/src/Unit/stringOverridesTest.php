<?php

/**
 * Testing the string overrides: search_config_string_overrides()
 */
use \Drupal\search_config;
class stringOverridesTest extends PHPUnit_Framework_TestCase {
    public $overrides = [];
    public function testStringOverrides() {
        $this->overrides = Drupal\search_config\search_config_string_overrides();
        $arr= [[],[],[],[],[],[],[],[],[],[],[],'default','default','default','default','default','default',[],[],];
        $this->assertTrue(arraysAreSimilar($arr, $this->overrides));
        function arraysAreSimilar($a, $b) {
            // if the indexes don't match, return immediately
            if (count(array_diff_assoc($a, $b))) {
                return false;
            }
            // compare the values between the two arrays, the indexes match.
            foreach($a as $k => $v) {
                if ($v !== $b[$k]) {
                    return false;
                }
            }
            // we have identical indexes, and no unequal values
            return true;
        }

    }
}
?>
