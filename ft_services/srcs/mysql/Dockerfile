FROM alpine:3.11

RUN apk add mysql mysql-client --no-cache

RUN addgroup mysql mysql

COPY ./my.cnf /etc/my.cnf
COPY ./startup.sh /tmp/startup.sh
COPY ./create_tables.sql /tmp
RUN chmod +x /tmp/startup.sh

VOLUME /var/lib/mysql

EXPOSE 3306

RUN chown -R mysql:mysql /var/lib && \
	mkdir /run/mysqld && \
	chown mysql:mysql /run/mysqld

# RUN :> createdatabase && \
# 	echo "CREATE DATABASE IF NOT EXISTS $DB_NAME;" >> createdatabase && \
# 	echo "CREATE USER '$DB_USER'@'%' IDENTIFIED BY '$DB_PASS';" >> createdatabase && \
# 	echo "GRANT ALL ON *.* TO '$DB_USER'@'%' IDENTIFIED BY '$DB_PASS' WITH GRANT OPTION;" >> createdatabase && \
# 	echo "FLUSH PRIVILEGES;" >> createdatabase

# CMD  mysql_install_db --user=mysql --datadir=/var/lib/mysql && \
# 	 /usr/bin/mysqld --user=mysql --init_file=/createdatabase
ENTRYPOINT ["/bin/sh", "/tmp/startup.sh"]
