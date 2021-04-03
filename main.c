#include <stdio.h>
#include "config.h"
#include "git2.h"

git_repository* cloneRepository(char *url) {
    git_repository *repo = NULL;
    const char *path = "/tmp/myrepo";
    git_clone(&repo, url, path, NULL);
    return repo;
}

int main() {

    git_libgit2_init();

    printf("Started libGit2 successfully.\n");

    git_repository *repo = cloneRepository("https://github.com/google/gson");

    git_strarray refs = {0};
    int error = git_reference_list(&refs, repo);

    printf("Result of git reference list: %d\n", error);

    for(int i = 0; i < refs.count; i++) {
        char *ref = refs.strings[i];
        printf("Found Ref: '%s'\n", ref);
    }
    
    git_libgit2_shutdown();

    return 0;
}