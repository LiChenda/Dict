A Simple Dictionary
=================
- [Intro](#intro)
- [Installation](#installation)
Intro
-----------------
This is a simple web application implemented by Python and C:

- Using Red-Black tree as data structure, which is implemented by C.
- Using Flask, a microframework for Python, as the web server.
- View the demo at [here](http://leohust.cn:5000) or compile and run it from source.

Installation
---------------------

###requirements:
- Python3 
- pip for Python3
- install Flask from pip:

    `$ pip install flask`

###compile  and run:
- compile core module written by c:

	`$ make`
- run server

    `$ python3 server.py`

Then the server will be running at [http://localhost:5000](http://localhost:5000)
