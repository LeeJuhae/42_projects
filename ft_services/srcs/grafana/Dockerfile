FROM alpine:3.11

RUN apk update && \
    apk upgrade && \
    apk add curl && \
    apk add wget && \
    apk add libc6-compat

RUN wget https://dl.grafana.com/oss/release/grafana-7.3.3.linux-amd64.tar.gz
RUN tar -zxvf grafana-7.3.3.linux-amd64.tar.gz

COPY grafana.db ./grafana-7.3.3/data/grafana.db

EXPOSE 3000

CMD cd grafana-7.3.3 && ./bin/grafana-server
