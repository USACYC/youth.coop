<?php
/**
 * @file
 * youth_membership_product.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function youth_membership_product_default_rules_configuration() {
  $items = array();
  $items['commerce_cart_add_to_cart_message'] = entity_import('rules_config', '{ "commerce_cart_add_to_cart_message" : {
      "LABEL" : "Display an Add to Cart message",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Cart" ],
      "REQUIRES" : [ "rules", "commerce_cart" ],
      "ON" : { "commerce_cart_product_add" : [] },
      "DO" : [
        { "drupal_message" : { "message" : "You chose the [commerce-product:title].  Please proceed to register and pay..." } }
      ]
    }
  }');
  $items['commerce_checkout_order_status_update'] = entity_import('rules_config', '{ "commerce_checkout_order_status_update" : {
      "LABEL" : "Update the order status on checkout completion",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout" ],
      "REQUIRES" : [ "commerce_order", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "DO" : [
        { "commerce_order_update_state" : { "commerce_order" : [ "commerce-order" ], "order_state" : "completed" } }
      ]
    }
  }');

      
  $items['rules_has_membership_product'] = entity_import('rules_config', '{ "rules_has_membership_product" : {
      "LABEL" : "has membership product",
      "PLUGIN" : "or",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_order" ],
      "USES VARIABLES" : { "order" : { "label" : "order", "type" : "commerce_order" } },
      "OR" : [
        { "commerce_order_contains_product" : {
            "commerce_order" : [ "site:current-cart-order" ],
            "product_id" : "membership_5",
            "operator" : "\\u003E=",
            "value" : "1"
          }
        },
        { "commerce_order_contains_product" : {
            "commerce_order" : [ "site:current-cart-order" ],
            "product_id" : "membership_10",
            "operator" : "\\u003E=",
            "value" : "1"
          }
        },
        { "commerce_order_contains_product" : {
            "commerce_order" : [ "site:current-cart-order" ],
            "product_id" : "membership_15",
            "operator" : "\\u003E=",
            "value" : "1"
          }
        },
        { "commerce_order_contains_product" : {
            "commerce_order" : [ "site:current-cart-order" ],
            "product_id" : "membership_20",
            "operator" : "\\u003E=",
            "value" : "1"
          }
        },
        { "commerce_order_contains_product" : {
            "commerce_order" : [ "site:current-cart-order" ],
            "product_id" : "membership_25",
            "operator" : "\\u003E=",
            "value" : "1"
          }
        },
        { "commerce_order_contains_product" : {
            "commerce_order" : [ "site:current-cart-order" ],
            "product_id" : "membership_30",
            "operator" : "\\u003E=",
            "value" : "1"
          }
        },
        { "commerce_order_contains_product" : {
            "commerce_order" : [ "site:current-cart-order" ],
            "product_id" : "membership_40",
            "operator" : "\\u003E=",
            "value" : "1"
          }
        }
      ]
    }
  }');
  $items['rules_redirect_to_checkout_after_login'] = entity_import('rules_config', '{ "rules_redirect_to_checkout_after_login" : {
      "LABEL" : "redirect to checkout after login",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_cart", "rules" ],
      "ON" : { "user_login" : [] },
      "IF" : [
        { "commerce_order_is_cart" : { "commerce_order" : [ "site:current-cart-order" ] } }
      ],
      "DO" : [ { "redirect" : { "url" : "checkout" } } ]
    }
  }');
  $items['rules_redirect_to_member_create_account'] = entity_import('rules_config', '{ "rules_redirect_to_member_create_account" : {
      "LABEL" : "Redirect to member create account",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_cart" ],
      "ON" : { "commerce_cart_product_add" : [] },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1" } }
          }
        },
        { "AND" : [
            { "component_rules_has_membership_product" : { "order" : [ "site:current-cart-order" ] } }
          ]
        }
      ],
      "DO" : [ { "redirect" : { "url" : "user\\/register" } } ]
    }
  }');
  return $items;
}
