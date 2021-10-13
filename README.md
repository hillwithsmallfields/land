# land
Scripts for landing on a new host.

Originally aimed at setting up a Raspberry Pi after I have overwritten its SD card with a new Raspbian; but I may make it more general.

Configurable using JSON, so the command lines don't get out of hand.

Also includes an Arduino sketch for autotyping the commands to do the setup (for Arduino Micro and the keyboard library).

The configuration file
======================

My default configuration file, which may be a useful example, is at
https://raw.githubusercontent.com/hillwithsmallfields/land/trunk/land.json

There are three sections to the config file:

  - hosts
  - host-classes
  - global
  
hosts
-----

This section is for recognizing hosts so that the program can assemble
the right configuration, and for giving the host its hostname.

The keys in the section are strings by which the host may be
recognized when unconfigured: a MAC address, an existing hostname, or
a serial number.

The values in this section should be dictionaries binding:

  - hostname
  - host-class --- looked up in the "host-classes" section.

host-classes
------------

This section defines named classes.

The keys are the strings bound to "host-class" in the "hosts" section
and to the elements of "superclasses" lists in this section.

The values in this section are dictionaries which can bind:

  - superclasses --- a list of classes to add when this class is used
  - apt-packages --- a list of packages to fetch with apt-get
  - pip-packages --- a list of packages to fetch with pip3
  - git-repos --- a list of clone URLs to use
  - dot-files --- a list of files to copy from your designated config repo
  - mounts --- a dictionary binding partition names to dictionaries defining:
  - - mount-point --- where in the filesystem to mount the ext-drive
  - - link-to-home
  - - take-ownership --- a flag saying to chown everything below mount-point once mounted
  - user --- your user-id
  - name --- your long name
  - projects-directory --- a directory to clone the github-list projects into
  - github-list --- the URL into github's user repo listing API
  - config-repo --- which of your repos your dot-files come from
  - root-actions --- shell commands to do just before changing uid to the user
  - user-actions --- shell commands to do at the end
  - system-directories --- directories to make as root, should be absolute
  - user-directories --- directories to make as the user, relative to the user's home directory

global
------

This can define any of the keys mentioned under host-classes, but
applies regardless of which classes are activated.
