# -*- coding: utf-8 -*-

# preconditions:
#   clang-format tool in PATH variable
#
# optional:
#   .clang-format style file near the script

import os, re
from subprocess import Popen, PIPE

rootdirs = ['../book', '../exercise']
cpp_pattern =  r'(\\begin\{lstlisting\})(\[[^\]]+\])?([\w\W]+?)([\t ]*\\end\{lstlisting\})'

def format_cpp_section(match):
  prefix = match.group(1)
  attributes = match.group(2)
  code_content = match.group(3)
  suffix = match.group(4)
  treat_as_cpp = False
  
  if attributes:
    tags = dict(map(str.strip, u.split("=")) for u in attributes[1:-1].split(","))
  
    if 'style' in tags and tags['style'].upper() == 'C++':
      treat_as_cpp = True
    if 'language' in tags and tags['language'].upper() == 'C++':
      treat_as_cpp = True
  else:
    # if no attributes specified
    treat_as_cpp = True
  
  if treat_as_cpp:
    formatter = Popen(['clang-format'], stdout=PIPE, stdin=PIPE, shell=True)
    cout, cerr = formatter.communicate(str.encode(code_content))
    attributes = attributes if attributes else ''
    return prefix + attributes + cout.decode() + suffix
  return match.group(0)

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
