
mkdir publish
cp ./obj/export_lib.ll ./publish/Dictionary.ll
cp ./LICENSE ./publish/
cp ./README.md ./publish/

cd publish
zip -q out.zip Dictionary.ll LICENSE README.md
mv out.zip ..
cd ..
rm -rf publish