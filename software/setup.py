from setuptools import setup, find_packages


setup(
    name="nrf24",
    version="0.1",
    author="whitequark",
    author_email="whitequark@whitequark.org",
    description="A Python package for interacting with Nordic nRF24Lx1 series chips",
    #long_description="""FIXME""",
    license="0-clause BSD License",
    install_requires=["libusb1"],
    packages=find_packages(),
    entry_points={
        "console_scripts": [
            "nrf24lu1-tool = nrf24.lu1_tool:main"
        ],
    },
    classifiers=[
        'Development Status :: 4 - Beta',
        'License :: OSI Approved', # ' :: 0-clause BSD License', (not in PyPI)
        'Topic :: Software Development :: Embedded Systems',
        'Topic :: System :: Hardware',
    ],
)
