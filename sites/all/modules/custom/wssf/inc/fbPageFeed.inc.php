<?php

class fbPageFeed {

	public $accessToken = 'PASS_ACCESS_TOKEN_WHEN_INSTANTIATING_CLASS';
	public $version = 'v2.4/';

	public function __construct($accessToken = null, $version = 'v2.4/') {
		if(!extension_loaded('curl')) trigger_error('fbPageFeed requires PHP cURL', E_USER_ERROR);
		if(is_null($accessToken)) trigger_error('access token must be supplied', E_USER_ERROR);
		$this->accessToken = $accessToken;
		$this->version = $version;
	}

	public function getInfo($page_id = null, $fields = null) {

		if (is_null($page_id)) trigger_error('fbPageFeed->getInfo requires page_id', E_USER_ERROR);
		if (is_null($fields)) {
			$fields = 'link,name,cover,picture';
		}

		$url = 'https://graph.facebook.com/' . $this->version . $page_id;
		$url .= '?fields='.$fields;
		$url .= '&access_token='.$this->accessToken;

		// call graph API
		$ch = curl_init();
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
		curl_setopt($ch, CURLOPT_TIMEOUT, 500);
		curl_setopt($ch, CURLOPT_URL, $url);
		$response = curl_exec($ch);
		curl_close($ch);

		return json_decode($response, TRUE);

	}

	public function getFeed($page_id = null, $limit = null, $fields = null) {

		if (is_null($page_id)) trigger_error('fbPageFeed->getFeed requires page_id', E_USER_ERROR);
		if (is_null($fields)) {
			$fields = 'picture,full_picture,actions,admin_creator,application,call_to_action,caption,child_attachments,description,from,icon,object_id,parent_id,link,message,message_tags,name,place,status_type,story_tags,to,with_tags,created_time,type,via,width';
		}
		if (is_array($fields)) {
			$fields_array = $fields;
			$fields = implode(',', $fields);
		} else {
			$fields_array = explode(',', $fields);
		}

		$url = 'https://graph.facebook.com/' . $this->version . $page_id . '/posts';
		$url .= '?fields='.$fields;
		$url .= '&access_token='.$this->accessToken;
		if (!is_null($limit) && (intval($limit) == $limit)) { $url .= '&limit='.$limit; }

		// call graph API
		$ch = curl_init();
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
		curl_setopt($ch, CURLOPT_TIMEOUT, 500);
		curl_setopt($ch, CURLOPT_URL, $url);
		$response = curl_exec($ch);
		curl_close($ch);

		return json_decode($response, TRUE);
	}

}
