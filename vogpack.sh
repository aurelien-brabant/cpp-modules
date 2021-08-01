#! /bin/sh

set -e

# Package CPP module to be pushed to the vogsphere
# Usage: ./vogpack <module_number>

if [ $# -eq 0 ]; then
	printf "Usage: ./vogpack <module_number>\n"
	exit 1
fi

MODULE="module-0$1"

if [ -d "$MODULE" ]; then
	printf "Packaging $MODULE for push to the vogsphere...\n"

	VOGPACKED="/tmp/vogpack-$MODULE"
	rm -rf "$VOGPACKED"
	cp -r "$MODULE" "$VOGPACKED"
	cp ./template.Makefile "$VOGPACKED"
	cp .gitignore "$VOGPACKED"

	if [ "$(uname)" == "Darwin" ]; then
		find "$VOGPACKED" -type d -name "ex*" -maxdepth 1 | xargs -I{} sh -c "sed -i '' 's|../../template.Makefile|../template.Makefile|g' {}/Makefile; make fclean -C {};"
	else
		find "$VOGPACKED" -type d -name "ex*" -maxdepth 1 | xargs -I{} sh -c "sed -i 's|../../template.Makefile|../template.Makefile|g' {}/Makefile; make fclean -C {};"
	fi

	cd "$VOGPACKED"
	git init
	git add .
	git commit -m "vogpacked: ready for defense!"

	printf "\033[0;32mPackaged successfully at $VOGPACKED\033[0m\n"

else
	printf "\033[0;31mCould not find directory module-0$1.\033[0m\n"
fi
