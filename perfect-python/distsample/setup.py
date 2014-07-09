from setuptools import setup

with open('README.txt') as f:
    readme = f.read()

setup(
        name="distsample.todolist",
        packages=['distsample.todolist'],
        version="0.1",
        author="Kentaro Kawano",
        author_email="kentaro.kawano@example.com",
        url="https://github.com/kawaken/book-reading",
        description="a todo list",
        long_description=readme,
        classifiers=[
            "Development Status :: 3 - Alpha",
            "Programing Language :: Python :: 3",
            "Programing Language :: Python :: 3.4",
        ]
)
