<?php
/*
  This code is part of FusionDirectory (http://www.fusiondirectory.org/)
  Copyright (C) 2013 FusionDirectory

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
*/

class opsiManagement extends simpleManagement
{
  // Tab definition
  protected $objectName   = "opsi";
  protected $objectTypes  = array('opsiProfile', 'opsiSoftwareList');//, 'opsiOnDemandList');

  protected $departmentBrowser      = FALSE;
  protected $departmentRootVisible  = FALSE;
  protected $baseMode               = FALSE;

  function __construct($config, $ui)
  {
    $this->acl_base = $config->current['BASE'];
    parent::__construct($config, $ui);
    $this->headpage->setBase($this->acl_base); // May be done by simpleManagement when departementBrowser is FALSE?
  }
  /* Return plugin informations for acl handling */
  static function plInfo()
  {
    return array(
      'plShortName'   => _('OPSI'),
      'plDescription' => _('OPSI profile management'),
      'plIcon'        => 'plugins/opsi/images/icon.png',
      'plPriority'    => 32,
      'plSection'     => 'admin',
      'plCategory'    => array('opsiProfile'),

      'plProvidedAcls' => array()
    );
  }
}
?>