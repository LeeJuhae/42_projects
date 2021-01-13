# minikube start --driver=virtualbox

echo "Install >> MetalLB"
kubectl get configmap kube-proxy -n kube-system -o yaml | \
sed -e "s/strictARP: false/strictARP: true/" | \
kubectl diff -f - -n kube-system
kubectl get configmap kube-proxy -n kube-system -o yaml | \
sed -e "s/strictARP: false/strictARP: true/" | \
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml
# On first install only
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"

# configmap 생성
kubectl apply -f metallb-config.yaml

eval $(minikube docker-env)

cd ./srcs
echo -e "Nginx image build"
docker build -t service-nginx ./nginx

echo -e "Nginx configmap 생성"
kubectl create configmap nginx-configmap --from-file=./nginx/srcs/default.conf --from-file=./nginx/srcs/proxy.conf
kubectl apply -f ./nginx/nginx-ssh-configmap.yaml
echo -e "Nginx deployment 생성"
kubectl apply -f ./nginx/nginx.yaml

echo "Finish"
minikube dashboard
