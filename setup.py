from distutils.core import setup, Extension

boost_module = Extension('sort',
                         sources=['src/sort/sort.cpp'],
                         libraries=['boost_python37'],
                         extra_compile_args=['-O2', '-Wall'])

setup(name='sort',
      version='0.1.0',
      author='kohei-yamato',
      package_dir={'': 'src'},
      packages=['sort'],
      ext_modules=[boost_module])
