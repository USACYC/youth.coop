<?php
/*
+--------------------------------------------------------------------+
| CiviCRM version 4.7                                                |
+--------------------------------------------------------------------+
| Copyright CiviCRM LLC (c) 2004-2016                                |
+--------------------------------------------------------------------+
| This file is a part of CiviCRM.                                    |
|                                                                    |
| CiviCRM is free software; you can copy, modify, and distribute it  |
| under the terms of the GNU Affero General Public License           |
| Version 3, 19 November 2007 and the CiviCRM Licensing Exception.   |
|                                                                    |
| CiviCRM is distributed in the hope that it will be useful, but     |
| WITHOUT ANY WARRANTY; without even the implied warranty of         |
| MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.               |
| See the GNU Affero General Public License for more details.        |
|                                                                    |
| You should have received a copy of the GNU Affero General Public   |
| License and the CiviCRM Licensing Exception along                  |
| with this program; if not, contact CiviCRM LLC                     |
| at info[AT]civicrm[DOT]org. If you have questions about the        |
| GNU Affero General Public License or the licensing of CiviCRM,     |
| see the CiviCRM license FAQ at http://civicrm.org/licensing        |
+--------------------------------------------------------------------+
*/
/**
 * @package CRM
 * @copyright CiviCRM LLC (c) 2004-2016
 *
 * Generated from xml/schema/CRM/Contact/RelationshipType.xml
 * DO NOT EDIT.  Generated by CRM_Core_CodeGen
 */
require_once 'CRM/Core/DAO.php';
require_once 'CRM/Utils/Type.php';
class CRM_Contact_DAO_RelationshipType extends CRM_Core_DAO
{
  /**
   * static instance to hold the table name
   *
   * @var string
   */
  static $_tableName = 'civicrm_relationship_type';
  /**
   * static instance to hold the field values
   *
   * @var array
   */
  static $_fields = null;
  /**
   * static instance to hold the keys used in $_fields for each field.
   *
   * @var array
   */
  static $_fieldKeys = null;
  /**
   * static instance to hold the FK relationships
   *
   * @var string
   */
  static $_links = null;
  /**
   * static instance to hold the values that can
   * be imported
   *
   * @var array
   */
  static $_import = null;
  /**
   * static instance to hold the values that can
   * be exported
   *
   * @var array
   */
  static $_export = null;
  /**
   * static value to see if we should log any modifications to
   * this table in the civicrm_log table
   *
   * @var boolean
   */
  static $_log = true;
  /**
   * Primary key
   *
   * @var int unsigned
   */
  public $id;
  /**
   * name for relationship of contact_a to contact_b.
   *
   * @var string
   */
  public $name_a_b;
  /**
   * label for relationship of contact_a to contact_b.
   *
   * @var string
   */
  public $label_a_b;
  /**
   * Optional name for relationship of contact_b to contact_a.
   *
   * @var string
   */
  public $name_b_a;
  /**
   * Optional label for relationship of contact_b to contact_a.
   *
   * @var string
   */
  public $label_b_a;
  /**
   * Optional verbose description of the relationship type.
   *
   * @var string
   */
  public $description;
  /**
   * If defined, contact_a in a relationship of this type must be a specific contact_type.
   *
   * @var string
   */
  public $contact_type_a;
  /**
   * If defined, contact_b in a relationship of this type must be a specific contact_type.
   *
   * @var string
   */
  public $contact_type_b;
  /**
   * If defined, contact_sub_type_a in a relationship of this type must be a specific contact_sub_type.
   *
   * @var string
   */
  public $contact_sub_type_a;
  /**
   * If defined, contact_sub_type_b in a relationship of this type must be a specific contact_sub_type.
   *
   * @var string
   */
  public $contact_sub_type_b;
  /**
   * Is this relationship type a predefined system type (can not be changed or de-activated)?
   *
   * @var boolean
   */
  public $is_reserved;
  /**
   * Is this relationship type currently active (i.e. can be used when creating or editing relationships)?
   *
   * @var boolean
   */
  public $is_active;
  /**
   * class constructor
   *
   * @return civicrm_relationship_type
   */
  function __construct()
  {
    $this->__table = 'civicrm_relationship_type';
    parent::__construct();
  }
  /**
   * Returns all the column names of this table
   *
   * @return array
   */
  static function &fields()
  {
    if (!(self::$_fields)) {
      self::$_fields = array(
        'id' => array(
          'name' => 'id',
          'type' => CRM_Utils_Type::T_INT,
          'title' => ts('Relationship Type ID') ,
          'description' => 'Primary key',
          'required' => true,
        ) ,
        'name_a_b' => array(
          'name' => 'name_a_b',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Relationship Type Name A to B') ,
          'description' => 'name for relationship of contact_a to contact_b.',
          'maxlength' => 64,
          'size' => CRM_Utils_Type::BIG,
        ) ,
        'label_a_b' => array(
          'name' => 'label_a_b',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Relationship Type Label A to B') ,
          'description' => 'label for relationship of contact_a to contact_b.',
          'maxlength' => 64,
          'size' => CRM_Utils_Type::BIG,
        ) ,
        'name_b_a' => array(
          'name' => 'name_b_a',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Relationship Type Name B to A') ,
          'description' => 'Optional name for relationship of contact_b to contact_a.',
          'maxlength' => 64,
          'size' => CRM_Utils_Type::BIG,
        ) ,
        'label_b_a' => array(
          'name' => 'label_b_a',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Relationship Type Label B to A') ,
          'description' => 'Optional label for relationship of contact_b to contact_a.',
          'maxlength' => 64,
          'size' => CRM_Utils_Type::BIG,
        ) ,
        'description' => array(
          'name' => 'description',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Relationship Description') ,
          'description' => 'Optional verbose description of the relationship type.',
          'maxlength' => 255,
          'size' => CRM_Utils_Type::HUGE,
        ) ,
        'contact_type_a' => array(
          'name' => 'contact_type_a',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Contact Type for Contact A') ,
          'description' => 'If defined, contact_a in a relationship of this type must be a specific contact_type.',
          'maxlength' => 12,
          'size' => CRM_Utils_Type::TWELVE,
          'html' => array(
            'type' => 'Select',
          ) ,
          'pseudoconstant' => array(
            'table' => 'civicrm_contact_type',
            'keyColumn' => 'name',
            'labelColumn' => 'label',
            'condition' => 'parent_id IS NULL',
          )
        ) ,
        'contact_type_b' => array(
          'name' => 'contact_type_b',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Contact Type for Contact B') ,
          'description' => 'If defined, contact_b in a relationship of this type must be a specific contact_type.',
          'maxlength' => 12,
          'size' => CRM_Utils_Type::TWELVE,
          'html' => array(
            'type' => 'Select',
          ) ,
          'pseudoconstant' => array(
            'table' => 'civicrm_contact_type',
            'keyColumn' => 'name',
            'labelColumn' => 'label',
            'condition' => 'parent_id IS NULL',
          )
        ) ,
        'contact_sub_type_a' => array(
          'name' => 'contact_sub_type_a',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Contact Subtype A') ,
          'description' => 'If defined, contact_sub_type_a in a relationship of this type must be a specific contact_sub_type.
    ',
          'maxlength' => 64,
          'size' => CRM_Utils_Type::BIG,
          'html' => array(
            'type' => 'Select',
          ) ,
          'pseudoconstant' => array(
            'table' => 'civicrm_contact_type',
            'keyColumn' => 'name',
            'labelColumn' => 'label',
            'condition' => 'parent_id IS NOT NULL',
          )
        ) ,
        'contact_sub_type_b' => array(
          'name' => 'contact_sub_type_b',
          'type' => CRM_Utils_Type::T_STRING,
          'title' => ts('Contact Subtype B') ,
          'description' => 'If defined, contact_sub_type_b in a relationship of this type must be a specific contact_sub_type.
    ',
          'maxlength' => 64,
          'size' => CRM_Utils_Type::BIG,
          'html' => array(
            'type' => 'Select',
          ) ,
          'pseudoconstant' => array(
            'table' => 'civicrm_contact_type',
            'keyColumn' => 'name',
            'labelColumn' => 'label',
            'condition' => 'parent_id IS NOT NULL',
          )
        ) ,
        'is_reserved' => array(
          'name' => 'is_reserved',
          'type' => CRM_Utils_Type::T_BOOLEAN,
          'title' => ts('Relationship Type is Reserved') ,
          'description' => 'Is this relationship type a predefined system type (can not be changed or de-activated)?',
        ) ,
        'is_active' => array(
          'name' => 'is_active',
          'type' => CRM_Utils_Type::T_BOOLEAN,
          'title' => ts('Relationship Type is Active') ,
          'description' => 'Is this relationship type currently active (i.e. can be used when creating or editing relationships)?
    ',
          'default' => '1',
        ) ,
      );
    }
    return self::$_fields;
  }
  /**
   * Returns an array containing, for each field, the arary key used for that
   * field in self::$_fields.
   *
   * @return array
   */
  static function &fieldKeys()
  {
    if (!(self::$_fieldKeys)) {
      self::$_fieldKeys = array(
        'id' => 'id',
        'name_a_b' => 'name_a_b',
        'label_a_b' => 'label_a_b',
        'name_b_a' => 'name_b_a',
        'label_b_a' => 'label_b_a',
        'description' => 'description',
        'contact_type_a' => 'contact_type_a',
        'contact_type_b' => 'contact_type_b',
        'contact_sub_type_a' => 'contact_sub_type_a',
        'contact_sub_type_b' => 'contact_sub_type_b',
        'is_reserved' => 'is_reserved',
        'is_active' => 'is_active',
      );
    }
    return self::$_fieldKeys;
  }
  /**
   * Returns the names of this table
   *
   * @return string
   */
  static function getTableName()
  {
    return CRM_Core_DAO::getLocaleTableName(self::$_tableName);
  }
  /**
   * Returns if this table needs to be logged
   *
   * @return boolean
   */
  function getLog()
  {
    return self::$_log;
  }
  /**
   * Returns the list of fields that can be imported
   *
   * @param bool $prefix
   *
   * @return array
   */
  static function &import($prefix = false)
  {
    if (!(self::$_import)) {
      self::$_import = array();
      $fields = self::fields();
      foreach($fields as $name => $field) {
        if (CRM_Utils_Array::value('import', $field)) {
          if ($prefix) {
            self::$_import['relationship_type'] = & $fields[$name];
          } else {
            self::$_import[$name] = & $fields[$name];
          }
        }
      }
    }
    return self::$_import;
  }
  /**
   * Returns the list of fields that can be exported
   *
   * @param bool $prefix
   *
   * @return array
   */
  static function &export($prefix = false)
  {
    if (!(self::$_export)) {
      self::$_export = array();
      $fields = self::fields();
      foreach($fields as $name => $field) {
        if (CRM_Utils_Array::value('export', $field)) {
          if ($prefix) {
            self::$_export['relationship_type'] = & $fields[$name];
          } else {
            self::$_export[$name] = & $fields[$name];
          }
        }
      }
    }
    return self::$_export;
  }
}
