#!/usr/bin/env python
# -*- coding: utf-8 -*-
import requests, sys, json, os, pprint

pp = pprint.PrettyPrinter(indent=4)

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
	url = "https://leetcode.com/graphql/"

	@staticmethod
	def get_problem_name(pid):
		data = None

		payload = "{\"query\":\"query problemsetQuestionList($categorySlug: String, $limit: Int, $skip: Int, $filters: QuestionListFilterInput) {\\n  problemsetQuestionList: questionList(\\n    categorySlug: $categorySlug\\n    limit: $limit\\n    skip: $skip\\n    filters: $filters\\n  ) {\\n    total: totalNum\\n    questions: data {\\n      acRate\\n      difficulty\\n      freqBar\\n      frontendQuestionId: questionFrontendId\\n      isFavor\\n      paidOnly: isPaidOnly\\n      status\\n      title\\n      titleSlug\\n      topicTags {\\n        name\\n        id\\n        slug\\n      }\\n      hasSolution\\n      hasVideoSolution\\n    }\\n  }\\n}\",\"variables\":{\"categorySlug\":\"\",\"skip\":0,\"limit\":10,\"filters\":{\"searchKeywords\":\"@pid@\"}}}"
		payload = payload.replace('@pid@', str(pid))
		headers = {
		'Content-Type': 'application/json',
		}
		r = requests.request("POST", LeetCode.url, headers=headers, data=payload, timeout=3)
		if r.status_code == requests.codes.ok:
			# Get the problem data
			pd = json.loads(r.text)['data']['problemsetQuestionList']['questions']

		title = ''
		difficulty = None
		pass_flag = False
		# iterate through the problem list
		for i in pd:
			# the problem id matched
			if int(i['frontendQuestionId']) == int(pid):
				pass_flag = True
				difficulty = i['difficulty']
				title = i['title']

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
