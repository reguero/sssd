/*
   SSSD

   NSS Configuratoin DB

   Copyright (C) Simo Sorce <ssorce@redhat.com>	2008

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#define CONFDB_FILE "config.ldb"

struct confdb_ctx;

int confdb_add_param(struct confdb_ctx *cdb,
                     bool replace,
                     const char *section,
                     const char *attribute,
                     const char **values);


int confdb_get_param(struct confdb_ctx *cdb,
                     TALLOC_CTX *mem_ctx,
                     const char *section,
                     const char *attribute,
                     char ***values);

int confdb_get_string(struct confdb_ctx *cdb, TALLOC_CTX *ctx,
                      const char *section, const char *attribute,
                      const char *defstr, char **result);

int confdb_get_int(struct confdb_ctx *cdb, TALLOC_CTX *ctx,
                   const char *section, const char *attribute,
                   int defval, int *result);

int confdb_init(TALLOC_CTX *mem_ctx,
                struct event_context *ev,
                struct confdb_ctx **cdb_ctx,
                char *confdb_location);

int confdb_get_domains(struct confdb_ctx *cdb,
                       TALLOC_CTX *mem_ctx,
                       char ***values);
