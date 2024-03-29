#!/usr/bin/env python
# -*- coding: utf-8 -*-
import requests, sys, json, os

class uhunt:
	@staticmethod
	def get_problem_name_by_id(i):
		r = requests.get(f'https://uhunt.onlinejudge.org/api/p/num/{i}')
		rt = None
		if r.status_code == requests.codes.ok:
			prob = json.loads(r.text)
			rt = prob['title']
		return rt

def uva_handle(prob_num, sub=None):
	name = uhunt.get_problem_name_by_id(prob_num)
	if name == None:
		sys.exit('Failed to get the proble name')

	if len(sys.argv) > 3:
		prob_num = '{}_{}'.format(prob_num, sys.argv)
	# Gen files
	if os.system('bash gen.sh uva "{}" "{}"'.format(prob_num, name)):
		print('Failed to gen Uva {} - {}'.format(prob_num, name))
		return False
	else:
		return True

# /html/body/div[3]/div[2]/div/ul/li[contains(@class, 'task')]/a
class CSES:
	url = ''

	@staticmethod
	def get_problem_info_by_pid(pid):
		r = requests.get(CSES.url, timeout=3)
		if r.status_code == requests.codes.ok:
			pass

class LeetCode:
	url = 'https://leetcode.com/api/problems/algorithms/'

	@staticmethod
	def get_problem_name(pid):
		data = None

		r = requests.get(LeetCode.url, timeout=3)
		if r.status_code == requests.codes.ok:
			# Get the problem data
			pd = json.loads(r.text)['stat_status_pairs']

		title = ''
		difficulty = None
		pass_flag = False
		# iterate through the problem list
		for i in pd:
			# the problem id matched
			if i['stat']['frontend_question_id'] == int(pid):
				pass_flag = True
				difficulty = {
					1: 'Easy',
					2: 'Medium',
					3: 'Hard'
				}[i['difficulty']['level']]
				title = i['stat']['question__title']

		if pass_flag:
			return 'Leetcode {diff} {id}. {title}'.format(diff=difficulty, id=pid, title=title)
		else:
			return 'Leetcode diff id. title'

def usage():
	print('Usage: {} <OJ name> <Prob id> []'.format(sys.argv[0]))

def main():
	oj = sys.argv[1]
	prob_num = sys.argv[2]
	sub = None
	if len(sys.argv) > 3:
		sub = sys.argv[3]

	# TODO
	if oj.lower() == 'uva':
		uva_handle(prob_num, sub)
	elif oj.lower() == 'leetcode':
		print(LeetCode.get_problem_name(sys.argv[2]))
	else:
		print('Unsupported Online Judge!')

if __name__ == '__main__':
	if len(sys.argv) < 3 or len(sys.argv) > 4:
		usage()
	else:
		main()
