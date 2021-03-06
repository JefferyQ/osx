BUILDIT = ./Common/Scripts/buildit.pl
BUILDROOT = /tmp

KERBEROS_SUBMISSION = $(BUILDROOT)/KerberosSubmission

SUBMISSION_NAME = Kerberos
SUBMISSION_SOURCES = $(KERBEROS_SUBMISSION)/$(SUBMISSION_NAME)
SUBMISSION = $(KERBEROS_SUBMISSION)/$(SUBMISSION_NAME).tgz

KFM_PROJECT = Kerberos

LIBRARIES_JAMFILE = ./Common/Scripts/KfMLibraries.jam
LIBRARIES_PROJECT = KerberosLibraries
LIBRARIES_BUILD = $(BUILDROOT)/KerberosLibraries

CLIENTS_JAMFILE = ./Common/Scripts/KfMClients.jam
CLIENTS_PROJECT = KerberosClients
CLIENTS_BUILD = $(BUILDROOT)/KerberosClients

INSTALLER_DST_PATH = $(BUILDROOT)/$(SUBMISSION_NAME).dst
MAKEINSTALLER = $(SUBMISSION_SOURCES)/Common/Scripts/MakeKerberosInstaller.sh

ORDERFILE = /AppleInternal/OrderFiles/Kerberos.order

# determining the architecture:
ifeq ($(shell arch), i386)
	ARCH_ARGS = -arch i386 -arch ppc
else
	ARCH_ARGS = -arch ppc
endif

# Default values:  (normally set by buildit at Apple)
# Some of these may come from the environment and buildit doesn't use make -e 
# so we have to wrap them with ifndefs:

ifndef MACOSX_DEPLOYMENT_TARGET
MACOSX_DEPLOYMENT_TARGET = 10.4
endif
ifndef INSTALL_MODE_FLAG
INSTALL_MODE_FLAG = u+w,go-w,a+rX
endif

BUILD_CONFIGURATION = Release
RC_ProjectName := $(KFM_PROJECT)
BUILT_PRODUCTS_DIR := $(SYMROOT)/BuiltProducts
# FRAMEWORK_SEARCH_PATHS := $(INSTALLER_DST_PATH)/System/Library/Frameworks $(INSTALLER_DST_PATH)/System/Library/PrivateFrameworks

VARIABLES = OBJROOT SYMROOT DSTROOT SUBLIBROOTS RC_XBS RC_JASPER RC_CFLAGS RC_NONARCH_CFLAGS \
	RC_ARCHS RC_hppa RC_i386 RC_m68k RC_ppc RC_ppc64 RC_sparc RC_OS RC_RELEASE \
	RC_ProjectName RC_ProjectSourceVersion RC_ProjectBuildVersion RC_ReleaseStatus NEXT_ROOT \
	BUILT_PRODUCTS_DIR INSTALL_MODE_FLAG FRAMEWORK_SEARCH_PATHS MACOSX_DEPLOYMENT_TARGET
ENVIRONMENT := $(strip $(foreach VAR, $(VARIABLES), $(if $(value $(VAR)),"$(VAR)=$(value $(VAR))",)))


PKINIT_FILES = \
	KerberosFramework/Kerberos5/Sources/include/pkinit_apple_utils.h \
	KerberosFramework/Kerberos5/Sources/include/pkinit_asn1.h \
	KerberosFramework/Kerberos5/Sources/include/pkinit_cert_store.h \
	KerberosFramework/Kerberos5/Sources/include/pkinit_client.h \
	KerberosFramework/Kerberos5/Sources/include/pkinit_cms.h \
	KerberosFramework/Kerberos5/Sources/lib/krb5/krb/pkinit_apple_asn1.c \
	KerberosFramework/Kerberos5/Sources/lib/krb5/krb/pkinit_apple_cert_store.c \
	KerberosFramework/Kerberos5/Sources/lib/krb5/krb/pkinit_apple_client.c \
	KerberosFramework/Kerberos5/Sources/lib/krb5/krb/pkinit_apple_cms.c \
	KerberosFramework/Kerberos5/Sources/lib/krb5/krb/pkinit_apple_utils.c \
	KerberosFramework/Kerberos5/Sources/kdc/pkinit_apple_server.c

# So we don't have to manually set and export everything
.EXPORT_ALL_VARIABLES:

#
# Targets to create the submission:
#

pathcheck:
	@echo "Checking for home directory relative paths:"
	BADFILES=`find . -type f \! -name $(USER).\* \! -path \*/.svn/\* -print0 | xargs -0 grep $(HOME)` ; \
	if [ ! -z "$$BADFILES" ] ; then echo "Offending files:" ; echo "$$BADFILES" ; false ; fi
	@echo "done."

orderfilecheck:
	if [ ! -f "$(ORDERFILE)"       ] ; then echo "No order file at $(ORDERFILE)"       ; false ; fi
    
# Hack to place pkinit sources in tree
pkinit_sources:
	for FILE in $(PKINIT_FILES) ; do \
		if [ ! -f "$$FILE" ] ; then echo "Creating '$$FILE'" ; touch "$$FILE" ; fi ; \
	done


# Install the sources into the submission folder, strip .svn directories and executable bits and tar up the submission
make_submission: pathcheck orderfilecheck pkinit_sources
	@echo "Removing old submission... "
	if [ -d "$(KERBEROS_SUBMISSION)" ]; then chmod -R u+w "$(KERBEROS_SUBMISSION)" && rm -rf "$(KERBEROS_SUBMISSION)"; fi
	@echo "Creating submission... "
	mkdir -p "$(KERBEROS_SUBMISSION)"
	make "SRCROOT=$(SUBMISSION_SOURCES)" installsrc
	find "$(SUBMISSION_SOURCES)" -type d -name \.svn -print0 | xargs -0 rm -r
	gnutar -czf "$(SUBMISSION)" -C "$(KERBEROS_SUBMISSION)" "$(SUBMISSION_NAME)"
	rm -rf "$(SUBMISSION_SOURCES)"

# Unpack the submission
unpack_submission: make_submission
	@echo "Unpacking submission... "
	gnutar -xzpf "$(SUBMISSION)" -C "$(KERBEROS_SUBMISSION)"

# Make a build directory
dst_root:	
	@echo "Removing old destination directory... "
	if [ -d "$(INSTALLER_DST_PATH)" ]; then chmod -R u+w "$(INSTALLER_DST_PATH)" && rm -rf "$(INSTALLER_DST_PATH)"; fi
	mkdir -p "$(INSTALLER_DST_PATH)"

# Someday apple may want to build the clients and libraries separately.  If so, here's a test of it.
split_build_submission: unpack_submission dst_root
	@echo "Removing old build directories... "
	if [ -d "$(LIBRARIES_BUILD)"    ]; then chmod -R u+w "$(LIBRARIES_BUILD)"    && rm -rf "$(LIBRARIES_BUILD)"; fi
	if [ -d "$(CLIENTS_BUILD)"      ]; then chmod -R u+w "$(CLIENTS_BUILD)"      && rm -rf "$(CLIENTS_BUILD)"; fi
	@echo "Running test build of target '$(LIBRARIES_PROJECT)'... "
	mkdir -p "$(LIBRARIES_BUILD)"
	(cd "$(SUBMISSION_SOURCES)" && BUILDIT_DIR=$(LIBRARIES_BUILD) && export BUILDIT_DIR && \
	perl "$(BUILDIT)" . $(ARCH_ARGS) -release $(USER) -project $(LIBRARIES_PROJECT) -merge "$(INSTALLER_DST_PATH)")
	@echo "Running test build of target '$(CLIENTS_PROJECT)'... "
	mkdir -p "$(CLIENTS_BUILD)"
	(cd "$(SUBMISSION_SOURCES)" && BUILDIT_DIR=$(CLIENTS_BUILD)   && export BUILDIT_DIR && \
	perl "$(BUILDIT)" . $(ARCH_ARGS) -release $(USER) -project $(CLIENTS_PROJECT) -merge "$(INSTALLER_DST_PATH)")

# Build the submission, just like apple will (we hope)
build_submission: unpack_submission dst_root
	@echo "Running test build... "
	(cd "$(SUBMISSION_SOURCES)" && BUILDIT_DIR=$(BUILDROOT) && export BUILDIT_DIR && \
	perl "$(BUILDIT)" . $(ARCH_ARGS) -release $(USER) -project $(RC_ProjectName) -merge "$(INSTALLER_DST_PATH)")

# Create the installer from the built submission
makeinstaller: build_submission
	sh $(MAKEINSTALLER) "$(SUBMISSION_SOURCES)" "$(INSTALLER_DST_PATH)" "$(KERBEROS_SUBMISSION)"

kfm: makeinstaller

krb5-configure:
	(cd KerberosFramework/Kerberos5/Sources && sh ./util/reconf --force)

doc:
	(cd KerberosFramework/KerberosIdentityManagement/Projects && doxygen Doxyfile)
	osascript Common/Scripts/bbedit-update-doc.scpt


#
# Apple build system targets:
#

# install sources from working directory into SRCROOT
installsrc:
	mkdir -p "$(SRCROOT)"
	gnutar -cf - . | gnutar -xpf - -C "$(SRCROOT)"
	find "$(SRCROOT)" -type f -print0 | xargs -0 chmod 644        
	chmod a+x "$(SRCROOT)/KerberosFramework/Kerberos5/Sources/config/mkinstalldirs"
	chmod a+x "$(SRCROOT)/KerberosFramework/KerberosErrors/Scripts/compile_et"

installhdrs:
	@echo "WARNING: installhdrs target disabled to avoid running krb5 build system twice."

all:
	(cd "$(SRCROOT)/Common/Projects" && \
	xcodebuild -target "$(RC_ProjectName)" -configuration $(BUILD_CONFIGURATION) build $(ENVIRONMENT))

install:
	(cd "$(SRCROOT)/Common/Projects" && \
	xcodebuild -target "$(RC_ProjectName)" -configuration $(BUILD_CONFIGURATION) install $(ENVIRONMENT))
	mkdir -p $(DSTROOT)/usr/local/OpenSourceVersions
	cp $(SRCROOT)/$(RC_ProjectName).plist $(DSTROOT)/usr/local/OpenSourceVersions/$(RC_ProjectName).plist
	mkdir -p $(DSTROOT)/usr/local/OpenSourceLicenses
	cp $(SRCROOT)/$(RC_ProjectName).html $(DSTROOT)/usr/local/OpenSourceLicenses/$(RC_ProjectName).html
	install -d -m 0755 $(DSTROOT)/usr/share/sandbox/
	install -C -m 0644 $(SRCROOT)/krb5kdc.sb $(DSTROOT)/usr/share/sandbox/krb5kdc.sb

clean:
	(cd "$(SRCROOT)/Common/Projects" && \
	xcodebuild -target "$(RC_ProjectName)" -configuration $(BUILD_CONFIGURATION) clean $(ENVIRONMENT))
