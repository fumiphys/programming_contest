use ::procon_tools::atcoder::AtCoder;
use ::procon_tools::contests::Contests;

fn main() {
    let cname: String = "abc136".to_string();
    let pname: String = "a".to_string();
    let ac = AtCoder::new(cname, pname);
    match ac.get_testcases() {
        Ok(res) => {
            println!("{:?}", res);
        },
        Err(err) => println!("Error: {}.", err),
    }
}
