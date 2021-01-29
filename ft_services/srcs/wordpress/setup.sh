cd /www
while :
do
    mysqladmin -h mysql ping
    if [ $? == 0 ]
    then
        break
    fi
    sleep 10
done
wp config create --dbname=wordpress --dbuser=mysql --dbpass=password --dbhost=mysql:3306
# wp db create
wp core install --title=wordpress --admin_user=juhlee --admin_password=password --admin_email=juhlee@student.42seoul.kr #--skip-email --url=192.168.99.240:5050
# wp user create jonas aa@student.codam.nl  --user_pass=lemao

php-fpm7
nginx
while true; do
	sleep 10
	ps | grep nginx | grep master
	if [ $? == 1 ]; then break
	fi
	ps | grep php-fpm | grep master
	if [ $? == 1 ]; then break
	fi
done
