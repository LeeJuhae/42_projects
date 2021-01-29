FROM alpine:3.11

RUN apk update && \
	apk upgrade && \
	apk add nginx \
	openssl \
	openssh --no-cache

RUN mkdir -p /run/nginx && mkdir /www

#Generates new ssl certifacate
RUN openssl genrsa -out /etc/ssl/certs/domain.key 2048 && \
    openssl req -x509 -days 356 -nodes -new -key /etc/ssl/certs/domain.key \
    -subj '/C=KO/ST=Seoul/L=Gaepodong/O=42Seoul/CN=ft_services' -out /etc/ssl/certs/domain.crt

#Creates ssh key and set user and password
RUN ssh-keygen -A
RUN adduser -D user
RUN echo "user:user" | chpasswd

#Configures nginx
COPY ./nginx.conf etc/nginx/nginx.conf
COPY ./index.html www
COPY ./ngxstart.sh ./
RUN chmod +x ngxstart.sh

EXPOSE 80 443 22

CMD ./ngxstart.sh
# CMD nginx && /usr/sbin/sshd && tail -f /dev/null
