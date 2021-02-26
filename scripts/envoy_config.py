import yaml
import json
import copy 
import requests

def config(base_port, n):
    with open("/root/quantra/envoy/quantra.yaml", 'r') as stream:
        try:
            data = yaml.safe_load(stream)
            endpoint = data['static_resources']['clusters'][0]['load_assignment']['endpoints'][0]
            del data['static_resources']['clusters'][0]['load_assignment']['endpoints'][0]
            for i in range(n):    
                endpoint['lb_endpoints'][0]['endpoint']['address']['socket_address']['port_value'] = base_port + i
                data['static_resources']['clusters'][0]['load_assignment']['endpoints'].append(copy.deepcopy(endpoint))
            with open('data.yaml', 'w') as outfile:
                yaml.dump(data, outfile)
        except yaml.YAMLError as exc:
            print(exc)

def check_clusters_health():
    response = requests.get('http://localhost:9901/clusters?format=json')
    data = response.json()
    for host in data['cluster_statuses'][0]['host_statuses']:
        port = host['address']['socket_address']['port_value']
        if 'failed_active_health_check' in host['health_status']:
            print('ERROR Quantra server running at port: ' + str(port) + ' NOT RUNNING')
        else:
            print('Quantra server running at port: ' + str(port) + ' OK')


