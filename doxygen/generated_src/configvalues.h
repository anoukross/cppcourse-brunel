/* WARNING: This file is generated!
 * Do not edit this file, but edit config.xml instead and run
 * python configgen.py -map config.xml to regenerate this file!
 */
#ifndef CONFIGVALUES_H
#define CONFIGVALUES_H

#include <qdict.h>
#include <qstrlist.h>
#include <qcstring.h>
#include "settings.h"

class ConfigValues
{
  public:
    static ConfigValues &instance() { static ConfigValues theInstance; return theInstance; }
    QCString DOXYFILE_ENCODING;
    QCString PROJECT_NAME;
    QCString PROJECT_NUMBER;
    QCString PROJECT_BRIEF;
    QCString PROJECT_LOGO;
    QCString OUTPUT_DIRECTORY;
    bool     CREATE_SUBDIRS;
    bool     ALLOW_UNICODE_NAMES;
    QCString OUTPUT_LANGUAGE;
    bool     BRIEF_MEMBER_DESC;
    bool     REPEAT_BRIEF;
    QStrList ABBREVIATE_BRIEF;
    bool     ALWAYS_DETAILED_SEC;
    bool     INLINE_INHERITED_MEMB;
    bool     FULL_PATH_NAMES;
    QStrList STRIP_FROM_PATH;
    QStrList STRIP_FROM_INC_PATH;
    bool     SHORT_NAMES;
    bool     JAVADOC_AUTOBRIEF;
    bool     QT_AUTOBRIEF;
    bool     MULTILINE_CPP_IS_BRIEF;
    bool     INHERIT_DOCS;
    bool     SEPARATE_MEMBER_PAGES;
    int      TAB_SIZE;
    QStrList ALIASES;
    QStrList TCL_SUBST;
    bool     OPTIMIZE_OUTPUT_FOR_C;
    bool     OPTIMIZE_OUTPUT_JAVA;
    bool     OPTIMIZE_FOR_FORTRAN;
    bool     OPTIMIZE_OUTPUT_VHDL;
    QStrList EXTENSION_MAPPING;
    bool     MARKDOWN_SUPPORT;
    int      TOC_INCLUDE_HEADINGS;
    bool     AUTOLINK_SUPPORT;
    bool     BUILTIN_STL_SUPPORT;
    bool     CPP_CLI_SUPPORT;
    bool     SIP_SUPPORT;
    bool     IDL_PROPERTY_SUPPORT;
    bool     DISTRIBUTE_GROUP_DOC;
    bool     GROUP_NESTED_COMPOUNDS;
    bool     SUBGROUPING;
    bool     INLINE_GROUPED_CLASSES;
    bool     INLINE_SIMPLE_STRUCTS;
    bool     TYPEDEF_HIDES_STRUCT;
    int      LOOKUP_CACHE_SIZE;
    bool     EXTRACT_ALL;
    bool     EXTRACT_PRIVATE;
    bool     EXTRACT_PACKAGE;
    bool     EXTRACT_STATIC;
    bool     EXTRACT_LOCAL_CLASSES;
    bool     EXTRACT_LOCAL_METHODS;
    bool     EXTRACT_ANON_NSPACES;
    bool     HIDE_UNDOC_MEMBERS;
    bool     HIDE_UNDOC_CLASSES;
    bool     HIDE_FRIEND_COMPOUNDS;
    bool     HIDE_IN_BODY_DOCS;
    bool     INTERNAL_DOCS;
    bool     CASE_SENSE_NAMES;
    bool     HIDE_SCOPE_NAMES;
    bool     HIDE_COMPOUND_REFERENCE;
    bool     SHOW_INCLUDE_FILES;
    bool     SHOW_GROUPED_MEMB_INC;
    bool     FORCE_LOCAL_INCLUDES;
    bool     INLINE_INFO;
    bool     SORT_MEMBER_DOCS;
    bool     SORT_BRIEF_DOCS;
    bool     SORT_MEMBERS_CTORS_1ST;
    bool     SORT_GROUP_NAMES;
    bool     SORT_BY_SCOPE_NAME;
    bool     STRICT_PROTO_MATCHING;
    bool     GENERATE_TODOLIST;
    bool     GENERATE_TESTLIST;
    bool     GENERATE_BUGLIST;
    bool     GENERATE_DEPRECATEDLIST;
    QStrList ENABLED_SECTIONS;
    int      MAX_INITIALIZER_LINES;
    bool     SHOW_USED_FILES;
    bool     SHOW_FILES;
    bool     SHOW_NAMESPACES;
    QCString FILE_VERSION_FILTER;
    QCString LAYOUT_FILE;
    QStrList CITE_BIB_FILES;
    bool     QUIET;
    bool     WARNINGS;
    bool     WARN_IF_UNDOCUMENTED;
    bool     WARN_IF_DOC_ERROR;
    bool     WARN_NO_PARAMDOC;
    bool     WARN_AS_ERROR;
    QCString WARN_FORMAT;
    QCString WARN_LOGFILE;
    QStrList INPUT;
    QCString INPUT_ENCODING;
    QStrList FILE_PATTERNS;
    bool     RECURSIVE;
    QStrList EXCLUDE;
    bool     EXCLUDE_SYMLINKS;
    QStrList EXCLUDE_PATTERNS;
    QStrList EXCLUDE_SYMBOLS;
    QStrList EXAMPLE_PATH;
    QStrList EXAMPLE_PATTERNS;
    bool     EXAMPLE_RECURSIVE;
    QStrList IMAGE_PATH;
    QCString INPUT_FILTER;
    QStrList FILTER_PATTERNS;
    bool     FILTER_SOURCE_FILES;
    QStrList FILTER_SOURCE_PATTERNS;
    QCString USE_MDFILE_AS_MAINPAGE;
    bool     SOURCE_BROWSER;
    bool     INLINE_SOURCES;
    bool     STRIP_CODE_COMMENTS;
    bool     REFERENCED_BY_RELATION;
    bool     REFERENCES_RELATION;
    bool     REFERENCES_LINK_SOURCE;
    bool     SOURCE_TOOLTIPS;
    bool     USE_HTAGS;
    bool     VERBATIM_HEADERS;
#if USE_LIBCLANG
    bool     CLANG_ASSISTED_PARSING;
#endif
#if USE_LIBCLANG
    QStrList CLANG_OPTIONS;
#endif
#if USE_LIBCLANG
    QCString CLANG_COMPILATION_DATABASE_PATH;
#endif
    bool     ALPHABETICAL_INDEX;
    int      COLS_IN_ALPHA_INDEX;
    QStrList IGNORE_PREFIX;
    bool     GENERATE_HTML;
    QCString HTML_OUTPUT;
    QCString HTML_FILE_EXTENSION;
    QCString HTML_HEADER;
    QCString HTML_FOOTER;
    QCString HTML_STYLESHEET;
    QStrList HTML_EXTRA_STYLESHEET;
    QStrList HTML_EXTRA_FILES;
    int      HTML_COLORSTYLE_HUE;
    int      HTML_COLORSTYLE_SAT;
    int      HTML_COLORSTYLE_GAMMA;
    bool     HTML_TIMESTAMP;
    bool     HTML_DYNAMIC_MENUS;
    bool     HTML_DYNAMIC_SECTIONS;
    int      HTML_INDEX_NUM_ENTRIES;
    bool     GENERATE_DOCSET;
    QCString DOCSET_FEEDNAME;
    QCString DOCSET_BUNDLE_ID;
    QCString DOCSET_PUBLISHER_ID;
    QCString DOCSET_PUBLISHER_NAME;
    bool     GENERATE_HTMLHELP;
    QCString CHM_FILE;
    QCString HHC_LOCATION;
    bool     GENERATE_CHI;
    QCString CHM_INDEX_ENCODING;
    bool     BINARY_TOC;
    bool     TOC_EXPAND;
    bool     GENERATE_QHP;
    QCString QCH_FILE;
    QCString QHP_NAMESPACE;
    QCString QHP_VIRTUAL_FOLDER;
    QCString QHP_CUST_FILTER_NAME;
    QCString QHP_CUST_FILTER_ATTRS;
    QCString QHP_SECT_FILTER_ATTRS;
    QCString QHG_LOCATION;
    bool     GENERATE_ECLIPSEHELP;
    QCString ECLIPSE_DOC_ID;
    bool     DISABLE_INDEX;
    bool     GENERATE_TREEVIEW;
    int      ENUM_VALUES_PER_LINE;
    int      TREEVIEW_WIDTH;
    bool     EXT_LINKS_IN_WINDOW;
    int      FORMULA_FONTSIZE;
    bool     FORMULA_TRANSPARENT;
    bool     USE_MATHJAX;
    QCString MATHJAX_FORMAT;
    QCString MATHJAX_RELPATH;
    QStrList MATHJAX_EXTENSIONS;
    QCString MATHJAX_CODEFILE;
    bool     SEARCHENGINE;
    bool     SERVER_BASED_SEARCH;
    bool     EXTERNAL_SEARCH;
    QCString SEARCHENGINE_URL;
    QCString SEARCHDATA_FILE;
    QCString EXTERNAL_SEARCH_ID;
    QStrList EXTRA_SEARCH_MAPPINGS;
    bool     GENERATE_LATEX;
    QCString LATEX_OUTPUT;
    QCString LATEX_CMD_NAME;
    QCString MAKEINDEX_CMD_NAME;
    bool     COMPACT_LATEX;
    QCString PAPER_TYPE;
    QStrList EXTRA_PACKAGES;
    QCString LATEX_HEADER;
    QCString LATEX_FOOTER;
    QStrList LATEX_EXTRA_STYLESHEET;
    QStrList LATEX_EXTRA_FILES;
    bool     PDF_HYPERLINKS;
    bool     USE_PDFLATEX;
    bool     LATEX_BATCHMODE;
    bool     LATEX_HIDE_INDICES;
    bool     LATEX_SOURCE_CODE;
    QCString LATEX_BIB_STYLE;
    bool     LATEX_TIMESTAMP;
    bool     GENERATE_RTF;
    QCString RTF_OUTPUT;
    bool     COMPACT_RTF;
    bool     RTF_HYPERLINKS;
    QCString RTF_STYLESHEET_FILE;
    QCString RTF_EXTENSIONS_FILE;
    bool     RTF_SOURCE_CODE;
    bool     GENERATE_MAN;
    QCString MAN_OUTPUT;
    QCString MAN_EXTENSION;
    QCString MAN_SUBDIR;
    bool     MAN_LINKS;
    bool     GENERATE_XML;
    QCString XML_OUTPUT;
    bool     XML_PROGRAMLISTING;
    bool     GENERATE_DOCBOOK;
    QCString DOCBOOK_OUTPUT;
    bool     DOCBOOK_PROGRAMLISTING;
    bool     GENERATE_AUTOGEN_DEF;
    bool     GENERATE_PERLMOD;
    bool     PERLMOD_LATEX;
    bool     PERLMOD_PRETTY;
    QCString PERLMOD_MAKEVAR_PREFIX;
    bool     ENABLE_PREPROCESSING;
    bool     MACRO_EXPANSION;
    bool     EXPAND_ONLY_PREDEF;
    bool     SEARCH_INCLUDES;
    QStrList INCLUDE_PATH;
    QStrList INCLUDE_FILE_PATTERNS;
    QStrList PREDEFINED;
    QStrList EXPAND_AS_DEFINED;
    bool     SKIP_FUNCTION_MACROS;
    QStrList TAGFILES;
    QCString GENERATE_TAGFILE;
    bool     ALLEXTERNALS;
    bool     EXTERNAL_GROUPS;
    bool     EXTERNAL_PAGES;
    QCString PERL_PATH;
    bool     CLASS_DIAGRAMS;
    QCString MSCGEN_PATH;
    QCString DIA_PATH;
    bool     HIDE_UNDOC_RELATIONS;
    bool     HAVE_DOT;
    int      DOT_NUM_THREADS;
    QCString DOT_FONTNAME;
    int      DOT_FONTSIZE;
    QCString DOT_FONTPATH;
    bool     CLASS_GRAPH;
    bool     COLLABORATION_GRAPH;
    bool     GROUP_GRAPHS;
    bool     UML_LOOK;
    int      UML_LIMIT_NUM_FIELDS;
    bool     TEMPLATE_RELATIONS;
    bool     INCLUDE_GRAPH;
    bool     INCLUDED_BY_GRAPH;
    bool     CALL_GRAPH;
    bool     CALLER_GRAPH;
    bool     GRAPHICAL_HIERARCHY;
    bool     DIRECTORY_GRAPH;
    QCString DOT_IMAGE_FORMAT;
    bool     INTERACTIVE_SVG;
    QCString DOT_PATH;
    QStrList DOTFILE_DIRS;
    QStrList MSCFILE_DIRS;
    QStrList DIAFILE_DIRS;
    QCString PLANTUML_JAR_PATH;
    QCString PLANTUML_CFG_FILE;
    QStrList PLANTUML_INCLUDE_PATH;
    int      DOT_GRAPH_MAX_NODES;
    int      MAX_DOT_GRAPH_DEPTH;
    bool     DOT_TRANSPARENT;
    bool     DOT_MULTI_TARGETS;
    bool     GENERATE_LEGEND;
    bool     DOT_CLEANUP;
    void init();
    struct Info
    {
      enum Type { Bool, Int, String, List, Unknown };
      Info(Type t) : type(t) {}
      virtual ~Info() {}
      Type type;
    };
    struct InfoBool : public Info
    {
      InfoBool(bool ConfigValues::*ptm) : Info(Info::Bool), item(ptm) {}
      bool ConfigValues::*item;
    };
    struct InfoInt : public Info
    {
      InfoInt(int ConfigValues::*ptm) : Info(Info::Int), item(ptm) {}
      int ConfigValues::*item;
    };
    struct InfoString : public Info
    {
      InfoString(QCString ConfigValues::*ptm) : Info(Info::String), item(ptm) {}
      QCString ConfigValues::*item;
    };
    struct InfoList : public Info
    {
      InfoList(QStrList ConfigValues::*ptm) : Info(Info::List), item(ptm) {}
      QStrList ConfigValues::*item;
    };
    const Info *get(const char *tag) const
    {
      return m_map.find(tag);
    }
  private:
    ConfigValues();
    QDict<Info> m_map;
};

#endif
