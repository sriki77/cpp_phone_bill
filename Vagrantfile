# -*- mode: ruby -*-
# vi: set ft=ruby :

$script = <<BOX_INIT
        apt-get update
        apt-get install -y cmake make libboost-all-dev libgtest-dev google-mock lcov

        # build gtest
        cd /usr/src/gtest
        sudo cmake .
        sudo make 
        sudo mv libg* /usr/lib/
BOX_INIT

VAGRANTFILE_API_VERSION = "2"

Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|
  config.vm.box = "precise32"
  config.vm.box_url = "http://files.vagrantup.com/precise32.box"
  config.vm.hostname = "cppenvcheck"
  config.vm.provision :shell, :inline=>$script
  config.vm.synced_folder ".", "/vagrant", :extra => "dmode=777,fmode=777"
end
