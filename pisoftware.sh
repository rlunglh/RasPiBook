#! /bin/bash
GREEN=`tput setaf 2`
NC=`tput sgr0`
#ntpdate pool.ntpdate.org
#echo $(tput setaf 2)update package lists$(tput sgr0)
#sudo apt-get update
#echo $(tput setaf 2)upgrade packages$(tput sgr0)
#sudo apt-get upgrade -y
echo $(tput setaf 2)set timezone to New York$(tput sgr0)
sudo rm /etc/localtime
sudo ln -s /usr/share/zoneinfo/America/New_York /etc/localtime
echo $(tput setaf 2)installing libreadline libcairo2 libpng build-essential expect$(tput sgr0)
sudo apt-get install -y libreadline-dev libcairo2-dev libpng12-dev build-essential expect
echo $(tput setaf 2)installing strace$(tput sgr0)
sudo apt-get install -y strace
echo $(tput setaf 2)installing xbase-clients$(tput sgr0)
sudo apt-get install -y xbase-clients
echo $(tput setaf 2)installing x11-apps$(tput sgr0)
sudo apt-get install -y x11-apps
echo $(tput setaf 2)installing nautilus - running command nautilus gives a graphical file browser$(tput sgr0)
sudo apt-get install -y nautilus
echo $(tput setaf 2)installing aptitude - a more friendly sudo apt-get type utility$(tput sgr0)
sudo apt-get install -y aptitude
echo $(tput setaf 2)installing xfce4 $(tput sgr0)
sudo apt-get install -y xfce4
echo $(tput setaf 2)installing xrdp $(tput sgr0)
sudo apt-get install -y xrdp
echo $(tput setaf 2)installing mosquitto mosquitto-client daemontools daemontools-run $(tput sgr0)
sudo apt-get install -y mosquitto mosquitto-clients daemontools daemontools-run
sudo apt-get remove realvnc-vnc-server -y
sudo apt-get install vnc4server -y
sudo service xrdp restart
#echo $(tput setaf 2)installing libreoffice - ms office type functionality$(tput sgr0)
#apt-get install -y libreoffice
echo $(tput setaf 2)installing ntp - sets up a daemon that keeps the time on the BBB synched to network time servers$(tput sgr0)
sudo apt-get install -y ntp
#echo $(tput setaf 2)installing linux-headers needed to build kernel modules$(tput sgr0)
#sudo apt-get install -y linux-headers-$(uname -r)
echo $(tput setaf 2)installing ddd - graphical debug tools$(tput sgr0)
sudo apt-get install -y  ddd
echo $(tput setaf 2)installing gedit - graphical editor$(tput sgr0)
sudo apt-get install -y gedit 
sudo apt-get install -y php5 php5-cgi
sudo apt-get install -y automake
echo $(tput setaf 2)installing lighttpd - to replace apache with lightweight web server$(tput sgr0)
sudo apt-get install -y lighttpd
echo $(tput setaf 2) lighttpd enable $(tput sgr0)
sudo lighttpd-enable-mod fastcgi-php
echo $(tput setaf 2)sart lighttpd  $(tput sgr0) 
sudo systemctl start lighttpd.service
echo $(tput setaf 2)installing mysql $(tput sgr0)
sudo apt-get install -y mysql-server mysql-client libmysqlclient-dev
echo $(tput setaf 2)installing subversion aptitude $(tput sgr0)
sudo apt-get install -y subversion aptitude  
wget http://www.microimagesys.com/Downloads/RasPi/cint.sh
wget http://www.microimagesys.com/Downloads/pi_picoc.tgz
wget http://www.microimagesys.com/Downloads/bluez.tgz
tar -xvpf bluez.tgz
cp blue*/myattrib/gatttool ./
rm -rf blue*
sudo apt-get install -y bluetooth-dev libmysqlclient-dev 
tar -xvpf pi_pico.tgz
sudo rm *.tgz
sudo apt-get install -t pocketsphinx* sphinxbase* espeak
chmod +x cint.sh
sudo apt-get install -y flex bison libgtk-3-dev libxml2-dev intltool libgda-5.0-dev libgtksourceview-3.0-dev itstool 
wget  http://ftp.gnome.org/mirror/gnome.org/sources/gdl/3.5/gdl-3.5.5.tar.xz
tar -xvpf gld*.xz
cd gdl*
./configure
make clean all
sudo make install
rm -rf gdl*
#sudo apt-get install -y anjuta
sudo apt-get install -y konsole kdevelop khelpcenter4 emma
git clone https://github.com/intel-iot-devkit/mraa.git
cd mraa
mkdir build
cd build
sudo apt-get install -y cmake
cmake ..
make clean all
sudo make install
cd /home/pi
echo $(tput setaf 2)building cint  $(tput sgr0)
echo "export CINTSYSDIR=~/cint" >> .profile
echo "export PATH=~/cint/bin:$PATH" >> .profile
./cint.sh
cd /home/pi
read -r -p "Do you want to restart the RasPi now? [y/N] " response
case $response in
    [yY][eE][sS]|[yY])
echo $(tput setaf 2)Shutting down NOW$(tput sgr0)
sudo shutdown -r now
esac
