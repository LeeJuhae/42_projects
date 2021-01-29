FROM alpine:3.11

RUN apk update && \
	apk upgrade && \
	apk add influxdb

EXPOSE 8086

CMD influxd run -config /etc/influxdb.conf
