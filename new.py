#!/usr/bin/env python
# -*- coding: utf-8 -*-
import requests, sys, json, os

url_base = 'https://uhunt.onlinejudge.org/api'
class uhunt:
	url_prob_id = url_base + '/p/num'

	@staticmethod
	def get_problem_name_by_id(i):
		r = requests.get(uhunt.url_prob_id + '/{}'.format(i))
		rt = None
		if r.status_code == requests.codes.ok:
			prob = json.loads(r.text)
			rt = prob['title']
		return rt

def uva_handle(prob_num):
	name = uhunt.get_problem_name_by_id(prob_num)
	if name == None:
		sys.exit('Failed to get the proble name')
	# Gen files
	if os.system('bash gen.sh uva "{}" "{}"'.format(prob_num, name)):
		print('Failed to gen Uva {} - {}'.format(prob_num, name))
		return False
	else:
		return True

def usage():
	print('Usage: {} <OJ name> <Prob id>'.format(sys.argv[0]))

def main():
	oj = sys.argv[1]
	prob_num = sys.argv[2]

	if oj.lower() == 'uva':
		uva_handle(prob_num)
	else:
		print('Unsupported Online Judge!')

if __name__ == '__main__':
	if len(sys.argv) != 3:
		usage()
	else:
		main()