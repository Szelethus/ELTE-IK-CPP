# -*- coding: utf-8 -*-

# preconditions:
#   clang-format tool in PATH variable
#
# optional:
#   .clang-format style file near the script

import os, re
from subprocess import Popen, PIPE

rootdirs = ['../book', '../exercise']
cpp_pattern =  r'(\\begin\{lstlisting\}(\[.*\])?)([\w\W]+?)([\t ]*\\end\{lstlisting\})'

def format_cpp_section(match):
  formatter = Popen(['clang-format'], stdout=PIPE, stdin=PIPE, shell=True)
  cout, cerr = formatter.communicate(str.encode(match.group(3)))
  return match.group(1) + cout.decode() + match.group(4)

for rootdir in rootdirs:
  for folder, subs, files in os.walk(rootdir):
    files = [ fi for fi in files if fi.endswith('.tex') ]
    for filename in files:
      print('formatting file: ' + filename)
      src = open(os.path.join(folder, filename), 'r', encoding='utf8')
      formatted = re.sub(cpp_pattern, format_cpp_section, src.read())
      src.close()
      
      src = open(os.path.join(folder, filename), 'w', encoding='utf8')
      src.write(formatted)
      src.close()
