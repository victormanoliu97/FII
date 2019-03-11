import http.server
from http import HTTPStatus
import socketserver
import os
import cgitb


class MainServer(http.server.CGIHTTPRequestHandler):
    def do_GET(self):
        """Serve a GET request."""
        if self.is_cgi():
            self.run_cgi()
        else:
            f = self.send_head()
            if f:
                try:
                    self.copyfile(f, self.wfile)
                finally:
                    f.close()
    def do_DELETE(self):
        """Serve a DELETE request.
        This is only implemented for CGI scripts.
        """

        if self.is_cgi():
            self.run_cgi()
        else:
            self.send_error(
                HTTPStatus.NOT_IMPLEMENTED,
                "Can only DELETE to CGI scripts")
    def do_PUT(self):
        """Serve a PUT request.
        This is only implemented for CGI scripts.
        """

        if self.is_cgi():
            self.run_cgi()
        else:
            self.send_error(
                HTTPStatus.NOT_IMPLEMENTED,
                "Can only PUT to CGI scripts")


port = 8000
ip = 'localhost'

cgitb.enable()
Handler = MainServer

os.chdir(os.path.join(os.path.dirname(__file__),'..','assets',))
with socketserver.TCPServer((ip, port), Handler) as httpd:
    print("serving at port", port)
    httpd.server_name = "test"
    httpd.server_port = port
    httpd.serve_forever()