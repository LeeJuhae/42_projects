FROM alpine:3.12

RUN apk add --no-cache mysql mysql-client bash

COPY ./entry.sh /tmp/entry.sh
RUN chmod +x /tmp/entry.sh

EXPOSE 3306

ENTRYPOINT ["/tmp/entry.sh"]

# FROM alpine:latest

# COPY ./srcs/* /tmp/
# RUN chmod 777 -R /tmp/*

# RUN apk update && apk add openrc mysql mysql-client
# # RUN apk update && apk add --no-cache openrc mysql mysql-client

# EXPOSE 3306

# ENTRYPOINT ["/tmp/entry.sh"]
