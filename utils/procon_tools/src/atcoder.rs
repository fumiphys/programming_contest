extern crate reqwest;
extern crate regex;
extern crate scraper;

use std::collections::HashMap;
use regex::Regex;
use scraper::{Html, Selector};
use super::contests::Contests;
use super::testcase::TestCase;

pub struct AtCoder {
    contest_name: String,
    problem_name: String,
}

impl AtCoder {
    pub fn new(cname: String, pname: String) -> AtCoder {
        AtCoder {
            contest_name: cname,
            problem_name: pname,
        }
    }
}

impl Contests for AtCoder {
    fn get_contest_name(&self) -> String {
        self.contest_name.clone()
    }
    fn get_problem_name(&self) -> String {
        self.problem_name.clone()
    }
    fn construct_url(&self) -> String {
        format!("https://atcoder.jp/contests/{cname}/tasks/{cname}_{pname}",
                cname=self.contest_name,
                pname=self.problem_name)
    }
    fn get_testcases(&self) -> Result<Vec<TestCase>, Box<std::error::Error>> {
        let url = self.construct_url();

        let mut response = reqwest::get(&url)?;
        assert!(response.status().is_success());
        let contents = response.text()?;

        let fragment = Html::parse_document(&contents);
        let selector = Selector::parse("h3").unwrap();

        let re_input = Regex::new(r"入力例[^\d]+(\d+)")?;
        let re_output = Regex::new(r"出力例[^\d]+(\d+)")?;
        let mut vin_title: HashMap<String, String> = HashMap::new();
        let mut vout_title: HashMap<String, String> = HashMap::new();
        let mut vin: HashMap<String, String> = HashMap::new();
        let mut vout: HashMap<String, String> = HashMap::new();

        for elm in fragment.select(&selector) {
            let texts: Vec<&str> = elm.text().collect();
            if texts.len() == 0 {
                continue
            }

            if let Some(caps) = re_input.captures(texts[0]) {
                let input_title: String = caps.get(0).map_or("".to_string(), |m| m.as_str().to_string());
                let id: String = caps.get(1).map_or("".to_string(), |m| m.as_str().to_string());
                if id.len() == 0 {
                    continue
                }
                vin_title.insert(id.clone(), input_title);

                let next_text = elm.next_sibling().unwrap();
                let next_text = next_text.first_child().unwrap();
                let input: String = next_text.value().as_text().unwrap().text.to_string();

                vin.insert(id, input);

                continue
            }

            if let Some(caps) = re_output.captures(texts[0]) {
                let output_title: String = caps.get(0).map_or("".to_string(), |m| m.as_str().to_string());
                let id: String = caps.get(1).map_or("".to_string(), |m| m.as_str().to_string());
                if id.len() == 0 {
                    continue
                }
                vout_title.insert(id.clone(), output_title);

                let next_text = elm.next_sibling().unwrap();
                let next_text = next_text.first_child().unwrap();
                let output: String = next_text.value().as_text().unwrap().text.to_string();

                vout.insert(id, output);

                continue
            }
        }

        let mut res: Vec<TestCase> = Vec::new();

        for (k, v) in &vin_title {
            if vin.contains_key(k) && vout_title.contains_key(k) && vout.contains_key(k) {
                res.push(TestCase::new(v.to_string(),
                                       vout_title.get(k).unwrap().to_string(),
                                       vin.get(k).unwrap().to_string(),
                                       vout.get(k).unwrap().to_string(),
                ));
            }
        }

        Ok(res)
    }
}
