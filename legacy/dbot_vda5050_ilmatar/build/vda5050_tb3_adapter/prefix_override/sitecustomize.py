import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/dbot2/dbot_vda5050_ilmatar/install/vda5050_tb3_adapter'
