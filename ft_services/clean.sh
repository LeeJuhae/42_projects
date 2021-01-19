## delete metallb
kubectl delete -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
kubectl delete -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml
kubectl delete -f ./metallb_config.yaml

kubectl delete deployment --all
kubectl delete services --all
kubectl delete replicaset --all
kubectl delete pods --all
kubectl delete pv,pvc --all
kubectl delete secret --all
kubectl delete configmap --all

##delete all docker images && containers (in case)
docker rmi $(docker images -q)
docker stop $(docker ps -a -q)
docker rm $(docker ps -a -q)
docker rmi $(docker images -q)
