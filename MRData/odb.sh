odb --version
echo "Start MRData initializing..."
echo "----------------------------"
odb -d sqlite --std c++11 --generate-schema --schema-format embedded --schema-name MRArticleMetaData --generate-query --generate-session mrarticlemetadata.h
odb -d sqlite --std c++11 --generate-schema --schema-format embedded --schema-name MRNoteData --generate-query --generate-session mrnotedata.h
echo "----------------------------"
echo "End MRData initializing..."
