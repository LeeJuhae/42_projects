mysql < var/www/html/phpmyadmin/sql/create_tables.sql -u root --skip-password

echo "show databases" | mysql;
echo "CREATE DATABASE IF NOT EXISTS $1" | mysql;
echo "Grant all privileges on *.* to '$2'@'%' identified by '$3' with grant option" | mysql;
echo "flush privileges" | mysql;
echo "show databases" | mysql;

