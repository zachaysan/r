import os

settings = dict(
    static_path=os.path.join(os.path.dirname(__file__), "..", "static"),
    template_path=os.path.join(os.path.dirname(__file__), "..", "templates"),
    cookie_secret="milkshakesomethingtotheyard",
    login_url="/login",
    xsrf_cookies=True,
    debut=True
)
