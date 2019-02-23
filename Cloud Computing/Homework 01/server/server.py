import cgitb
import http.server
import os
import socketserver

port = 8000
ip = 'localhost'

cgitb.enable()
Handler = http.server.CGIHTTPRequestHandler

os.chdir(os.path.join(os.path.dirname(__file__), '../' 'assets',))
with socketserver.TCPServer((ip, port), Handler) as httpd:
    print("serving at port", port)
    httpd.server_name = "test"
    httpd.server_port = port
    httpd.serve_forever()
