'''setup script
'''

from setuptools import setup


setup(
    name="procon_tools",
    version="0.0.0",
    install_requires=["argparse"],
    entry_points={
        "console_scripts": [
            "pc = app:main",
        ]
    }
)
