FROM alpine:3.11

RUN apk update && apk upgrade && apk add wget && apk add curl

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.15.3_static_linux_amd64.tar.gz
RUN tar -zxvf telegraf-1.15.3_static_linux_amd64.tar.gz
RUN mkdir /etc/telegraf
COPY telegraf.conf /etc/telegraf/telegraf.conf

EXPOSE 8125

CMD cd telegraf-1.15.3/usr && ./bin/telegraf
