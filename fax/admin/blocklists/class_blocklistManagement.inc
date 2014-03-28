<?php

/*
  This code is part of FusionDirectory (http://www.fusiondirectory.org/)
  Copyright (C) 2003-2010  Cajus Pollmeier
  Copyright (C) 2011-2013  FusionDirectory

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

class blocklist extends management
{
  // Tab definition
  protected $tabClass     = "faxblocktabs";
  protected $tabType      = "FAXBLOCKTABS";
  protected $aclCategory  = "gofaxlist";
  protected $aclPlugin    = "blocklistGeneric";
  protected $objectName   = "blocklist";

  /* Return plugin informations for acl handling */
  static function plInfo()
  {
    return array(
      "plShortName"   => _("Fax Blocklists"),
      "plDescription" => _("Fax Blocklists management"),
      "plIcon"        => "plugins/fax/images/iconBlocklists.png",
      "plSection"     => "admin",
      "plPriority"    => 12,
      "plCategory"    => array("gofaxlist"),

      "plProvidedAcls" => array()
    );
  }

  function __construct($config, $ui)
  {
    $this->config = $config;
    $this->ui     = $ui;

    $this->storagePoints = array(get_ou("faxBlocklistRDN"));

    $filter = new filter(get_template_path("blocklist-filter.xml", TRUE));
    $filter->setObjectStorage($this->storagePoints);
    $this->setFilter($filter);

    // Build headpage
    $headpage = new listing(get_template_path("blocklist-list.xml", TRUE));
    $headpage->setFilter($filter);

    parent::__construct($config, $ui, "blocklists", $headpage);
  }
}
?>