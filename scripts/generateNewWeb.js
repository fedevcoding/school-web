const path = require("path");
const { WEB_PATH } = require("./utils");
const fs = require("fs").promises;

async function main() {
 try {
  const name = process.argv[2];
  if (!name) {
   console.log("Please specify a name for the new web");
   return;
  }

  const webPath = path.join(WEB_PATH, name);
  const cssPath = path.join(WEB_PATH, name, "css");
  const pagesPath = path.join(WEB_PATH, name, "pages");
  const imagesPath = path.join(WEB_PATH, name, "images");

  await fs.mkdir(webPath);
  await fs.writeFile(
   path.join(webPath, "index.html"),
   `<!DOCTYPE html>
<html lang="it">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>${name}</title>

    <link rel='stylesheet' href='css/style.css' />
</head>

<body>

</body>

</html>
`
  );

  await fs.mkdir(cssPath);
  await fs.writeFile(path.join(webPath, "/css", "style.css"), "");

  await fs.mkdir(pagesPath);
  await fs.mkdir(imagesPath);
 } catch (err) {
  console.log(err);
 }
}
main();
