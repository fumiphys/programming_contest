use super::testcase::TestCase;

pub trait Contests {
    fn get_contest_name(&self) -> String;
    fn get_problem_name(&self) -> String;
    fn construct_url(&self) -> String;
    fn get_testcases(&self) -> Result<Vec<TestCase>, Box<std::error::Error>>;
}
