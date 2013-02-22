#!/usr/bin/python
from distutils.core import setup, Extension

igrf = Extension('finalfrontier.igrf', sources = ['igrf11.c',
    'igrf11module.c'], libraries = ['m', 'f2c'], library_dirs = ['/usr/lib/'])

cxform = Extension('finalfrontier.cxform', sources = ['cxformmodule.c',
    'cxform-manual.c', 'cxform-auto.c'])

setup(name='FinalFrontier',
    version='0.1',
    description='A collection of useful libraries for Earth & Space scientists',
    author='David Parunakian',
    author_email='dp@dp.io',
    ext_modules=[igrf, cxform],
	packages=["finalfrontier"])
