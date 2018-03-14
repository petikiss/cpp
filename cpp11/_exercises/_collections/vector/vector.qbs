import qbs

Project {
    minimumQbsVersion: "1.7.1"

    CppApplication {

        //cpp.cppFlags: "-std=c++11"

        consoleApplication: true
        files: [
            "main.cpp",
            "vector.cpp",
            "vector.h",
        ]

        Group {     // Properties for the produced executable
            fileTagsFilter: "application"
            qbs.install: true
        }
    }
}
