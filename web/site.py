import os

import tornado.ioloop
import tornado.web
from tornado import template

from config import settings


class BaseHandler(tornado.web.RequestHandler):
    def get_current_user(self):
        return self.get_secure_cookie("user")

class MainHandler(BaseHandler):
    def get(self):
        self.render("nukeio.html")

class EmailHandler(BaseHandler):
    def get(self):
        password = self.get_argument("password", None)
        if password != "nukeio974304":
            self.render("thanks.html")
        else:
            self.render("emails.txt")

    def post(self):
        email = self.get_argument("email")
        text = email + "\n"
        with open("templates/emails.txt", "a") as f:
            f.write(text)
        self.redirect("/email")

application = tornado.web.Application([
    (r"/", MainHandler),
    (r"/email", EmailHandler),
], **settings)

port = 3000
application.listen(port)
tornado.ioloop.IOLoop.instance().start()
