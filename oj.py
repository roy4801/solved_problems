#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os, sys
from pathlib import Path

import pname as ProblemName

CC = 'g++'
CFLAG = '-std=c++17 -I.'
DRY=False
PRINT_OUTPUT=True

def system(cmd):
	print(cmd)
	if not DRY:
		return os.system(cmd)
	else:
		return None
def popen(cmd):
	print(cmd)
	if not DRY:
		return os.popen(cmd).read()
	else:
		return None

class template:
	tem_file = 'template.cpp'
	content = None

	@staticmethod
	def get_content():
		with open(template.tem_file, 'r') as f:
			template.content = f.read()

	def __init__(self, path, **kargs):
		if template.content == None:
			template.get_content()
		self.gen(path, **kargs)
	# judge pid pname
	def gen(self, path, **kargs):
		con = template.content
		kargs['judge'] = kargs['judge'][0].upper() + kargs['judge'][1:] # first char toupper
		con = con.replace('{judge}', kargs['judge'])
		con = con.replace('{pid}', kargs['pid'])
		con = con.replace('{pname}', kargs['pname'])
		t = Path(path)
		with t.open('w', encoding='utf-8') as f:
			f.write(con)

class uva:
	need_arg = 3
	path = Path('./uva/')
	@staticmethod
	def do():
		res = 1
		for key, val in uva.__dict__.items():
			if sys.argv[2].lower() == key:
				res = uva.__dict__[key].__func__()
		if res == 1:
			uva.usage()
		return res

	@staticmethod
	def gen():
		pid = sys.argv[3]
		pname = sys.argv[4] if len(sys.argv) == 5 else None
		if pname == None: # TODO(roy4801): call api
			pname = ProblemName.uhunt.get_problem_name_by_id(pid[:pid.find('_')])
		# Create the files (.c, .in, .out)
		src = uva.path / '{}.cpp'.format(pid)
		din = uva.path / 'testdata' / '{}.in'.format(pid)
		dout = uva.path / 'testdata' / '{}.out'.format(pid)
		template(src, judge='uva', pid=pid, pname=pname)
		with din.open('w') as f1, dout.open('w') as f2:
			pass

	@staticmethod
	def usage():
		print('Usage: {} uva gen <pid> [pname]'.format(sys.argv[0],))

class LeetCode:
	need_arg = 3
	path = Path('./leetcode/')

	@staticmethod
	def do():
		res = 1
		for key, val in LeetCode.__dict__.items():
			if sys.argv[2].lower() == key:
				res = LeetCode.__dict__[key].__func__()
		if res == 1:
			LeetCode.usage()
		return res

	@staticmethod
	def gen():
		pid = sys.argv[3]
		pname = ProblemName.LeetCode.get_problem_name(pid)
		src = LeetCode.path / '{}.cpp'.format(pid)
		if pname:
			LeetCodeTemplate(src, title=pname)
		else:
			print('Wrong problem id...')

	@staticmethod
	def usage():
		print('Usage: {} leetcode gen <id>')

class LeetCodeTemplate:
	tem_file = 'leetcode/template.cpp'
	content = None

	@staticmethod
	def get_content():
		with open(LeetCodeTemplate.tem_file, 'r') as f:
			LeetCodeTemplate.content = f.read()

	def __init__(self, path, **kargs):
		LeetCodeTemplate.get_content()
		self.gen(path, **kargs)
	# judge pid pname
	def gen(self, path, **kargs):
		con = LeetCodeTemplate.content
		con = con.replace('{title}', kargs['title'])
		t = Path(path)
		with t.open('w', encoding='utf-8') as f:
			f.write(con)

support = {'uva': uva(), 'leetcode': LeetCode()}

def usage():
	print('Usage: {} <Online Judge> ...'.format(sys.argv[0]))
	print('Supported online judges: ', end='')
	for i, _ in support.items():
		print(i, end=' ')

if __name__ == '__main__':
	print(sys.argv)
	if len(sys.argv) < 2:
		usage()
		exit(1)
	res = 1
	for i, obj in support.items():
		if i == sys.argv[1].lower():
			if len(sys.argv) >= obj.need_arg:
				res = obj.do()
			else:
				obj.usage()
	exit(res)
