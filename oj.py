#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os, sys
import platform
import time
from pathlib import Path

import pname as ProblemName

CC = 'g++'
CFLAG = '-std=c++17 -I.'
DRY=False
PRINT_OUTPUT=True

def system(cmd):
	# print(cmd)
	if not DRY:
		return os.system(cmd)
	else:
		return None
def popen(cmd):
	# print(cmd)
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
			ui = pid.find('_')
			if ui != -1:
				pid = pid[:ui]
			pname = ProblemName.uhunt.get_problem_name_by_id(pid)
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

class CSES:
	need_arg = 3
	path = Path('./cses/')

	@staticmethod
	def do():
		res = 1

		op = sys.argv[2].lower()

		if op in CSES.__dict__:
			res = CSES.__dict__[op].__func__()
		if res == 1:
			CSES.usage()
		return res

	@staticmethod
	def gen():
		pid = sys.argv[3]
		pname = sys.argv[4]

		src_path = CSES.path / '{}.cpp'.format(pname.replace(' ', '_'))
		template(src_path, judge='CSES', pid=pid, pname=pname)
		print(src_path)
		system(f'code "{src_path}"')

	@staticmethod
	def usage():
		print('Usage: {} cses gen <pid> [pname]'.format(sys.argv[0],))

class LeetCode:
	need_arg = 3
	path = Path('./leetcode/')

	@staticmethod
	def do():
		res = 1

		op = sys.argv[2].lower()

		if op in LeetCode.__dict__:
			res = LeetCode.__dict__[op].__func__()
		if res == 1:
			LeetCode.usage()
		return res

	@staticmethod
	def gen():
		pid = sys.argv[3]
		try:
			pname = ProblemName.LeetCode.get_problem_name(pid)
		except:
			pname = ''
			pass
		src = LeetCode.path / '{}.cpp'.format(pid)
		if pname:
			LeetCodeTemplate(src, title=pname)
		else:
			print('Wrong problem id...')
			ans = input('Still generate the file? (y/N)') == 'y' or False
			if ans:
				LeetCodeTemplate(src, title='')
		system(f'code leetcode/{pid}.cpp')

	@staticmethod
	def cp():
		pid = sys.argv[3]
		print('Compiling...')
		if system(f'g++ -g leetcode/{pid}.cpp -I. -Ileetcode/ -std=c++17') == 0:
			print('Running...')

			st = time.time()
			if 'nt' in platform.system().lower():
				system('./a.exe')
			else:
				system('./a.out')
			elapsed = time.time() - st
			if elapsed < 1.0:
				elapsed = '{} ms'.format(elapsed*1000)
			else:
				elapsed = '{} s'.format(elapsed)
			print(f'Elapsed {elapsed}')

	@staticmethod
	def usage():
		print(f'Usage: {sys.argv[0]} leetcode', end=' ')
		flag = False
		for k, v in LeetCode.__dict__.items():
			if isinstance(v, staticmethod) and k != 'do':
				if flag:
					print('|', end='')
				print(k, end='')
				flag = True

class LeetCodeTemplate:
	tem_file = 'leetcode/template.cpp'
	content = None

	def __init__(self, path, **kargs):
		LeetCodeTemplate.get_content()
		self.gen(path, **kargs)

	@staticmethod
	def get_content():
		with open(LeetCodeTemplate.tem_file, 'r') as f:
			LeetCodeTemplate.content = f.read()

	# judge pid pname
	def gen(self, path, **kargs):
		con = LeetCodeTemplate.content
		con = con.replace('{title}', kargs['title'])
		t = Path(path)
		with t.open('w', encoding='utf-8') as f:
			f.write(con)
		print(f'Leetcode {path} created')

support = {
	'uva': uva(),
	'leetcode': LeetCode(),
	'cses': CSES()
}

def usage():
	print('Usage: {} <Online Judge> ...'.format(sys.argv[0]))
	print('Supported online judges: ', end='')
	for i, _ in support.items():
		print(i, end=' ')

if __name__ == '__main__':
	# print(sys.argv)
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
