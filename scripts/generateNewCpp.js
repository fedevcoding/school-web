const path = require("path");
const { CPP_PATH } = require("./utils");
const fs = require("fs").promises;

async function main() {
  try {
    const name = process.argv[2];
    if (!name) {
      console.log("Please specify a name for the new web");
      return;
    }

    await fs.writeFile(
      path.join(CPP_PATH, name + ".cpp"),
      `
#include <iostream>

using namespace std;

int main(void) {
    cout << "Hello world!" << endl;

    return 0;
}
`
    );
  } catch (err) {
    console.log(err);
  }
}
main();
